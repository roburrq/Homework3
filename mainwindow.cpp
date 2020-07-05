#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
	ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_connectButton_clicked()
{
	//If the client connected to the pipe successfully
	if (client.connect("\\\\.\\pipe\\ICS0025"))
		ui->statusBox->setPlainText("Connected");
	else
		ui->statusBox->setPlainText("Error connecting to pipe: " + client.errorString());
}

void MainWindow::on_breakButton_clicked()
{
	//If the client disconnected from the pipe successfully
	if (client.disconnect())
		ui->statusBox->setPlainText("Disconnected");
	else
		ui->statusBox->setPlainText("Error disconnecting from pipe: " + client.errorString());
}

void MainWindow::on_computeButton_clicked()
{
	//If the client computed the result successfully
	if (client.compute(ui->functionComboBox->currentText(), ui->x0SpinBox->value(),
					   ui->xNSpinBox->value(), ui->numPointsSpinBox->value(),
					   ui->orderSpinBox->value(), (QCPGraph::LineStyle)ui->lineStyleComboBox->currentIndex(),
					   ui->graph))
		ui->statusBox->setPlainText("Successfully computed curve");
	else
		ui->statusBox->setPlainText("Error computing curve: " + client.errorString());
}

void MainWindow::on_exitButton_clicked()
{
	//Exit the application
	QCoreApplication::quit();
}
