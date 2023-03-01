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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
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
    QLabel *radiusLabel;
    QLineEdit *radiusInput;
    QLabel *areaLabel1;
    QPushButton *countBtn;
    QLabel *areaLabel2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        radiusLabel = new QLabel(centralwidget);
        radiusLabel->setObjectName("radiusLabel");
        radiusLabel->setGeometry(QRect(100, 220, 80, 23));
        radiusInput = new QLineEdit(centralwidget);
        radiusInput->setObjectName("radiusInput");
        radiusInput->setGeometry(QRect(200, 220, 113, 29));
        areaLabel1 = new QLabel(centralwidget);
        areaLabel1->setObjectName("areaLabel1");
        areaLabel1->setGeometry(QRect(400, 220, 80, 23));
        countBtn = new QPushButton(centralwidget);
        countBtn->setObjectName("countBtn");
        countBtn->setGeometry(QRect(520, 350, 112, 34));
        areaLabel2 = new QLabel(centralwidget);
        areaLabel2->setObjectName("areaLabel2");
        areaLabel2->setGeometry(QRect(490, 220, 141, 31));
        areaLabel2->setFrameShape(QFrame::Panel);
        areaLabel2->setFrameShadow(QFrame::Sunken);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 29));
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
        radiusLabel->setText(QCoreApplication::translate("MainWindow", "\345\215\212\345\276\204\357\274\232", nullptr));
        areaLabel1->setText(QCoreApplication::translate("MainWindow", "\351\235\242\347\247\257:", nullptr));
        countBtn->setText(QCoreApplication::translate("MainWindow", "\350\256\241\347\256\227", nullptr));
        areaLabel2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
