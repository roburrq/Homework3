#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "pipeclient.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	private:
		Q_OBJECT
		Ui::MainWindow *ui;

		PipeClient client{this};

	public:
		MainWindow(QWidget *parent = nullptr);
		~MainWindow();

	private slots:
		void on_connectButton_clicked();
		void on_breakButton_clicked();
		void on_computeButton_clicked();
		void on_exitButton_clicked();
};
#endif // MAINWINDOW_H
