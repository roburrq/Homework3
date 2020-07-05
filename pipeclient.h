#ifndef PIPECLIENT_H
#define PIPECLIENT_H

#include <QLocalSocket>
#include "qcustomplot.h"


/// Class for communicating with a server, through a pipe
class PipeClient
{
	private:

		/// The socket for communicating with the pipe
		QLocalSocket pipe;


		/// The last error string
		QString lastError = "Unknown error";


	public:

		/// Class constructor
		PipeClient(QObject* parent = nullptr)
			: pipe(parent) {}


		/// Class destructor that disconnects from the server (if connected)
		~PipeClient();


		/// Function to connect to the pipe
		/// \param path The path to the pipe to connect to
		/// \return Whether the client managed to connect
		bool connect(const QString& path);


		/// Function to disconnect from the pipe
		/// \return Whether the client managed to disconnect
		bool disconnect();


		/// Function to draw onto the given plot using the given parameters
		/// \param function The function as a string
		/// \param x0 The start of the range
		/// \param xN The end of the range
		/// \param numPoints The number of points to draw
		/// \param order The order (in the case of Bessel functions)
		/// \param lineStyle The style of the line on the graph
		/// \param plot A pointer to the plot to draw onto
		bool compute(const QString& function, const double& x0, const double& xN,
					 const int& numPoints, const int& order, const QCPGraph::LineStyle& lineStyle,
					 QCustomPlot* plot);


		/// Function to get the last error as a human-readable string
		/// \return The error message
		QString errorString() const;

};

#endif // PIPECLIENT_H
