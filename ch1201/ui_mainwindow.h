/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *startBtn;
    QPushButton *stopBtn;
    QPushButton *quitBtn;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(507, 107);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        startBtn = new QPushButton(centralwidget);
        startBtn->setObjectName("startBtn");
        startBtn->setGeometry(QRect(50, 30, 111, 34));
        stopBtn = new QPushButton(centralwidget);
        stopBtn->setObjectName("stopBtn");
        stopBtn->setGeometry(QRect(190, 30, 111, 34));
        quitBtn = new QPushButton(centralwidget);
        quitBtn->setObjectName("quitBtn");
        quitBtn->setGeometry(QRect(330, 30, 111, 34));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        startBtn->setText(QCoreApplication::translate("MainWindow", "start", nullptr));
        stopBtn->setText(QCoreApplication::translate("MainWindow", "stop", nullptr));
        quitBtn->setText(QCoreApplication::translate("MainWindow", "quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
