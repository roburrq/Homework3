/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QPushButton *computeButton;
    QDoubleSpinBox *x0SpinBox;
    QLabel *orderLabel;
    QLabel *numPointsLabel;
    QLabel *x0Label;
    QPushButton *connectButton;
    QLabel *graphLabel;
    QPlainTextEdit *statusBox;
    QComboBox *functionComboBox;
    QPushButton *exitButton;
    QLabel *xNLabel;
    QSpinBox *numPointsSpinBox;
    QDoubleSpinBox *xNSpinBox;
    QSpinBox *orderSpinBox;
    QPushButton *breakButton;
    QCustomPlot *graph;
    QLabel *lineStyleLabel;
    QLabel *functionLabel;
    QComboBox *lineStyleComboBox;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(696, 361);
        MainWindow->setAutoFillBackground(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        computeButton = new QPushButton(centralwidget);
        computeButton->setObjectName(QString::fromUtf8("computeButton"));

        gridLayout_2->addWidget(computeButton, 12, 1, 1, 1);

        x0SpinBox = new QDoubleSpinBox(centralwidget);
        x0SpinBox->setObjectName(QString::fromUtf8("x0SpinBox"));
        x0SpinBox->setMinimum(-500.000000000000000);
        x0SpinBox->setMaximum(500.000000000000000);

        gridLayout_2->addWidget(x0SpinBox, 8, 0, 1, 1);

        orderLabel = new QLabel(centralwidget);
        orderLabel->setObjectName(QString::fromUtf8("orderLabel"));

        gridLayout_2->addWidget(orderLabel, 9, 1, 1, 1);

        numPointsLabel = new QLabel(centralwidget);
        numPointsLabel->setObjectName(QString::fromUtf8("numPointsLabel"));

        gridLayout_2->addWidget(numPointsLabel, 9, 0, 1, 1);

        x0Label = new QLabel(centralwidget);
        x0Label->setObjectName(QString::fromUtf8("x0Label"));

        gridLayout_2->addWidget(x0Label, 7, 0, 1, 1);

        connectButton = new QPushButton(centralwidget);
        connectButton->setObjectName(QString::fromUtf8("connectButton"));

        gridLayout_2->addWidget(connectButton, 12, 0, 1, 1);

        graphLabel = new QLabel(centralwidget);
        graphLabel->setObjectName(QString::fromUtf8("graphLabel"));

        gridLayout_2->addWidget(graphLabel, 7, 3, 1, 1);

        statusBox = new QPlainTextEdit(centralwidget);
        statusBox->setObjectName(QString::fromUtf8("statusBox"));
        statusBox->setReadOnly(true);

        gridLayout_2->addWidget(statusBox, 11, 0, 1, 2);

        functionComboBox = new QComboBox(centralwidget);
        functionComboBox->addItem(QString());
        functionComboBox->addItem(QString());
        functionComboBox->addItem(QString());
        functionComboBox->addItem(QString());
        functionComboBox->addItem(QString());
        functionComboBox->setObjectName(QString::fromUtf8("functionComboBox"));

        gridLayout_2->addWidget(functionComboBox, 3, 0, 1, 2);

        exitButton = new QPushButton(centralwidget);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));

        gridLayout_2->addWidget(exitButton, 14, 1, 1, 1);

        xNLabel = new QLabel(centralwidget);
        xNLabel->setObjectName(QString::fromUtf8("xNLabel"));

        gridLayout_2->addWidget(xNLabel, 7, 1, 1, 1);

        numPointsSpinBox = new QSpinBox(centralwidget);
        numPointsSpinBox->setObjectName(QString::fromUtf8("numPointsSpinBox"));
        numPointsSpinBox->setMaximum(500);

        gridLayout_2->addWidget(numPointsSpinBox, 10, 0, 1, 1);

        xNSpinBox = new QDoubleSpinBox(centralwidget);
        xNSpinBox->setObjectName(QString::fromUtf8("xNSpinBox"));
        xNSpinBox->setMinimum(-500.000000000000000);
        xNSpinBox->setMaximum(500.000000000000000);

        gridLayout_2->addWidget(xNSpinBox, 8, 1, 1, 1);

        orderSpinBox = new QSpinBox(centralwidget);
        orderSpinBox->setObjectName(QString::fromUtf8("orderSpinBox"));

        gridLayout_2->addWidget(orderSpinBox, 10, 1, 1, 1);

        breakButton = new QPushButton(centralwidget);
        breakButton->setObjectName(QString::fromUtf8("breakButton"));

        gridLayout_2->addWidget(breakButton, 14, 0, 1, 1);

        graph = new QCustomPlot(centralwidget);
        graph->setObjectName(QString::fromUtf8("graph"));

        gridLayout_2->addWidget(graph, 8, 3, 7, 2);

        lineStyleLabel = new QLabel(centralwidget);
        lineStyleLabel->setObjectName(QString::fromUtf8("lineStyleLabel"));

        gridLayout_2->addWidget(lineStyleLabel, 2, 3, 1, 1);

        functionLabel = new QLabel(centralwidget);
        functionLabel->setObjectName(QString::fromUtf8("functionLabel"));

        gridLayout_2->addWidget(functionLabel, 2, 0, 1, 1);

        lineStyleComboBox = new QComboBox(centralwidget);
        lineStyleComboBox->addItem(QString());
        lineStyleComboBox->addItem(QString());
        lineStyleComboBox->addItem(QString());
        lineStyleComboBox->addItem(QString());
        lineStyleComboBox->addItem(QString());
        lineStyleComboBox->addItem(QString());
        lineStyleComboBox->setObjectName(QString::fromUtf8("lineStyleComboBox"));

        gridLayout_2->addWidget(lineStyleComboBox, 3, 3, 1, 2);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        lineStyleComboBox->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "ICS0025", nullptr));
        computeButton->setText(QCoreApplication::translate("MainWindow", "Compute", nullptr));
        orderLabel->setText(QCoreApplication::translate("MainWindow", "Order:", nullptr));
        numPointsLabel->setText(QCoreApplication::translate("MainWindow", "Num Points:", nullptr));
        x0Label->setText(QCoreApplication::translate("MainWindow", "X0:", nullptr));
        connectButton->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        graphLabel->setText(QCoreApplication::translate("MainWindow", "Graph:", nullptr));
        functionComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Sine integral", nullptr));
        functionComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Cosine integral", nullptr));
        functionComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Bessel function", nullptr));
        functionComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Fresnel integral S", nullptr));
        functionComboBox->setItemText(4, QCoreApplication::translate("MainWindow", "Fresnel integral C", nullptr));

        exitButton->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        xNLabel->setText(QCoreApplication::translate("MainWindow", "Xn:", nullptr));
        breakButton->setText(QCoreApplication::translate("MainWindow", "Break", nullptr));
        lineStyleLabel->setText(QCoreApplication::translate("MainWindow", "Line Style", nullptr));
        functionLabel->setText(QCoreApplication::translate("MainWindow", "Function:", nullptr));
        lineStyleComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "None", nullptr));
        lineStyleComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Normal line", nullptr));
        lineStyleComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Step (left)", nullptr));
        lineStyleComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Step (right)", nullptr));
        lineStyleComboBox->setItemText(4, QCoreApplication::translate("MainWindow", "Step (center)", nullptr));
        lineStyleComboBox->setItemText(5, QCoreApplication::translate("MainWindow", "Impulse", nullptr));

    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
