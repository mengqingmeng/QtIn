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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *btnHostInfo;
    QPushButton *btnTcp;
    QPushButton *btnUdp;
    QPushButton *btnHttp;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(332, 199);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        btnHostInfo = new QPushButton(centralwidget);
        btnHostInfo->setObjectName("btnHostInfo");
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnHostInfo->sizePolicy().hasHeightForWidth());
        btnHostInfo->setSizePolicy(sizePolicy);

        gridLayout->addWidget(btnHostInfo, 0, 0, 1, 1);

        btnTcp = new QPushButton(centralwidget);
        btnTcp->setObjectName("btnTcp");
        sizePolicy.setHeightForWidth(btnTcp->sizePolicy().hasHeightForWidth());
        btnTcp->setSizePolicy(sizePolicy);

        gridLayout->addWidget(btnTcp, 0, 1, 1, 1);

        btnUdp = new QPushButton(centralwidget);
        btnUdp->setObjectName("btnUdp");
        sizePolicy.setHeightForWidth(btnUdp->sizePolicy().hasHeightForWidth());
        btnUdp->setSizePolicy(sizePolicy);

        gridLayout->addWidget(btnUdp, 1, 0, 1, 1);

        btnHttp = new QPushButton(centralwidget);
        btnHttp->setObjectName("btnHttp");
        sizePolicy.setHeightForWidth(btnHttp->sizePolicy().hasHeightForWidth());
        btnHttp->setSizePolicy(sizePolicy);

        gridLayout->addWidget(btnHttp, 1, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 332, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnHostInfo->setText(QCoreApplication::translate("MainWindow", "HostInfo", nullptr));
        btnTcp->setText(QCoreApplication::translate("MainWindow", "TCP", nullptr));
        btnUdp->setText(QCoreApplication::translate("MainWindow", "UDP", nullptr));
        btnHttp->setText(QCoreApplication::translate("MainWindow", "HTTP", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
