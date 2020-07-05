#include "pipeclient.h"

PipeClient::~PipeClient()
{
	//If the client is connected, disconnect
	if (pipe.state() == QLocalSocket::ConnectedState)
	{
		//Disconnect from the server
		//(we don't check whether it was successful,
		//because you can't do anything about it in a destructor)
		disconnect();
	}
}

bool PipeClient::connect(const QString& path)
{
	//If already connected
	if (pipe.state() != QLocalSocket::UnconnectedState)
	{
		//Set the error
		lastError = "Cannot connect to pipe, already connected";
		//Return failure
		return false;
	}

	//Start connecting to the pipe
	pipe.connectToServer(path);
	//If it immediately connected, return success
	if (pipe.state() == QLocalSocket::ConnectedState) return true;
	//Otherwise, wait for it to connect,
	//and if the socket couldn't connect after 30s
	if (!pipe.waitForConnected())
	{
		//Stop trying to connect
		pipe.disconnectFromServer();
		//Set the error
		lastError = pipe.errorString();
		//Return failure
		return false;
	}
	//Otherwise return success
	else return true;
}

bool PipeClient::disconnect()
{
	//If not connected
	if (pipe.state() != QLocalSocket::ConnectedState)
	{
		//Set the error
		lastError = "Cannot disconnect from unconnected pipe";
		//Return failure
		return false;
	}

	//Flag for whether sending the stop packet was successful
	bool success = true;
	{
		//Calculate the size of the stop packet
		int payloadSize = sizeof(int) + (strlen("Stop") * sizeof(QChar)) + 2;
		//Create a byte array
		QByteArray payload(payloadSize, 0);
		//Copy the payload size
		*(int*)payload.data() = payloadSize;
		//Copy the "Stop" message
		memcpy(payload.data() + sizeof(int), QString("Stop").data(), strlen("Stop") * sizeof(QChar));
		//Write the payload onto the pipe
		auto bytesWritten = pipe.write(payload);
		//If not all the bytes were written
		if (bytesWritten != payload.size())
		{
			//Set the error
			lastError = pipe.errorString();
			//Indicate error, but don't return because even if
			//the stop packet didn't send we still want to disconnect
			success = false;
		}
	}

	//Disconnect the pipe
	pipe.disconnectFromServer();
	//If it immediately disconnected, return success
	if (pipe.state() == QLocalSocket::UnconnectedState) return true;
	//Otherwise, wait for it to disconnect,
	//and if the socket couldn't disconnect after 30s
	if (!pipe.waitForDisconnected())
	{
		//Set the error
		lastError = pipe.errorString();
		//Return failure
		return false;
	}
	//Otherwise return success
	return success;
}

bool PipeClient::compute(const QString& function, const double& x0, const double& xN,
						 const int& numPoints, const int& order,
						 const QCPGraph::LineStyle& lineStyle, QCustomPlot* plot)
{
	{
		//Calculate the actual size of the function string in bytes
		//(including the two null bytes)
		int functionStrSize = (function.size() * sizeof(QChar)) + 2;

		//Calculate the length of the payload in bytes
		int payloadSize = sizeof(int) + functionStrSize +
				(sizeof(double) * 2) + (sizeof(int) * 2);

		//Create a byte array
		QByteArray payload(payloadSize, 0);
		//Create a pointer to the data
		char* pointer = payload.data();
		//Add the payload size to the payload
		memcpy(pointer, &payloadSize, sizeof(int));
		//Add the function to the payload
		memcpy(pointer += sizeof(int), function.constData(), function.size() * sizeof(QChar));
		//Add the range to the payload
		memcpy(pointer += functionStrSize, &x0, sizeof(double));
		memcpy(pointer += sizeof(double), &xN, sizeof(double));
		//Add the number of points to the payload
		memcpy(pointer += sizeof(double), &numPoints, sizeof(int));
		//Add the order to the payload
		memcpy(pointer += sizeof(int), &order, sizeof(int));

		//Write the payload onto the pipe
		auto bytesWritten = pipe.write(payload);
		//If not all the bytes were written
		if (bytesWritten != payload.size())
		{
			//Set the error
			lastError = pipe.errorString();
			//Return failure
			return false;
		}
	}

	//Wait 30s for a response
	if (!pipe.waitForReadyRead())
	{
		//Set the error
		lastError = pipe.errorString();
		//Return failure
		return false;
	}

	{
		//Peek at the size of the incoming payload
		int payloadSize;
		auto bytesRead = pipe.peek((char*)&payloadSize, sizeof(int));
		//If not all the bytes were read
		if (bytesRead != sizeof(int))
		{
			//Set the error
			lastError = pipe.errorString();
			//Return failure
			return false;
		}

		//Create a byte array for the incoming payload
		QByteArray payload(payloadSize, 0);
		//Read into the byte array
		bytesRead = pipe.read(payload.data(), payload.size());
		//If not all the bytes were read
		if (bytesRead != payload.size())
		{
			//Set the error
			lastError = pipe.errorString();
			//Return failure
			return false;
		}

		//Create a pointer to the data, starting past the payload size
		const char* pointer = payload.data() + sizeof(int);
		//Create a QString from the payload pointer
		QString string((const QChar*)pointer);
		//If the payload isn't a curve
		if (string != QString("Curve"))
		{
			//Set the error
			lastError = string;
			//Return failure
			return false;
		}
		//Go to the start of the curve pairs
		pointer += (string.size() * sizeof(QChar)) + 2;

		//Create an array for the X and Y points
		QVector<double> xPoints(numPoints), yPoints(numPoints);

		//Iterate over the points
		for (int i = 0; i < numPoints; ++i)
		{
			//Convert the pointer to a double then copy it to the pair
			xPoints[i] = *((double*)pointer + (i * 2));

			//Convert the pointer to a double then copy it to the pair
			yPoints[i] = *((double*)pointer + (i * 2) + 1);
		}

		//Determine the y range for the graph
		std::pair<double, double> yRange{0, 0};
		for (const auto& y : yPoints)
		{
			if (y < yRange.first)
				yRange.first = y;
			else if (y > yRange.second)
				yRange.second = y;
		}

		plot->clearGraphs();
		plot->addGraph();
		plot->graph(0)->setData(xPoints, yPoints);
		plot->xAxis->setLabel("x");
		plot->yAxis->setLabel("y");
		plot->xAxis->setRange(x0, xN);
		plot->yAxis->setRange(yRange.first, yRange.second);
		plot->graph(0)->setLineStyle(lineStyle);
		plot->replot();
	}

	return true;
}

QString PipeClient::errorString() const
{
	return lastError;
}
