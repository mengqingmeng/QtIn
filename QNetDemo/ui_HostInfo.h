/********************************************************************************
** Form generated from reading UI file 'HostInfo.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOSTINFO_H
#define UI_HOSTINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HostInfo
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QPushButton *btnAllAddress;
    QCheckBox *checkIpv4;
    QPushButton *btnHostInfo;
    QPushButton *btnIpOnfo;
    QPushButton *btnAllInterfaces;
    QPushButton *btnClear;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QDialog *HostInfo)
    {
        if (HostInfo->objectName().isEmpty())
            HostInfo->setObjectName("HostInfo");
        HostInfo->resize(400, 300);
        verticalLayout = new QVBoxLayout(HostInfo);
        verticalLayout->setObjectName("verticalLayout");
        widget = new QWidget(HostInfo);
        widget->setObjectName("widget");
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName("lineEdit");

        gridLayout->addWidget(lineEdit, 2, 1, 1, 1);

        btnAllAddress = new QPushButton(widget);
        btnAllAddress->setObjectName("btnAllAddress");

        gridLayout->addWidget(btnAllAddress, 0, 1, 1, 1);

        checkIpv4 = new QCheckBox(widget);
        checkIpv4->setObjectName("checkIpv4");

        gridLayout->addWidget(checkIpv4, 1, 0, 1, 1);

        btnHostInfo = new QPushButton(widget);
        btnHostInfo->setObjectName("btnHostInfo");

        gridLayout->addWidget(btnHostInfo, 0, 0, 1, 1);

        btnIpOnfo = new QPushButton(widget);
        btnIpOnfo->setObjectName("btnIpOnfo");

        gridLayout->addWidget(btnIpOnfo, 2, 0, 1, 1);

        btnAllInterfaces = new QPushButton(widget);
        btnAllInterfaces->setObjectName("btnAllInterfaces");

        gridLayout->addWidget(btnAllInterfaces, 1, 1, 1, 1);

        btnClear = new QPushButton(widget);
        btnClear->setObjectName("btnClear");

        gridLayout->addWidget(btnClear, 3, 1, 1, 1);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(HostInfo);
        widget_2->setObjectName("widget_2");
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        plainTextEdit = new QPlainTextEdit(widget_2);
        plainTextEdit->setObjectName("plainTextEdit");

        verticalLayout_2->addWidget(plainTextEdit);


        verticalLayout->addWidget(widget_2);


        retranslateUi(HostInfo);

        QMetaObject::connectSlotsByName(HostInfo);
    } // setupUi

    void retranslateUi(QDialog *HostInfo)
    {
        HostInfo->setWindowTitle(QCoreApplication::translate("HostInfo", "Dialog", nullptr));
        btnAllAddress->setText(QCoreApplication::translate("HostInfo", "QNetworkInterface::allAddress()", nullptr));
        checkIpv4->setText(QCoreApplication::translate("HostInfo", "\345\217\252\346\230\276\347\244\272IPv4\345\215\217\350\256\256\345\234\260\345\235\200", nullptr));
        btnHostInfo->setText(QCoreApplication::translate("HostInfo", "QHostInfo\350\216\267\345\217\226\346\234\254\346\234\272\344\270\273\346\234\272\345\220\215\345\222\214IP", nullptr));
        btnIpOnfo->setText(QCoreApplication::translate("HostInfo", "QHostInfo\346\237\245\350\257\242\345\237\237\345\220\215\347\232\204IP\345\234\260\345\235\200", nullptr));
        btnAllInterfaces->setText(QCoreApplication::translate("HostInfo", "QNetworkInterface::allInterfaces()", nullptr));
        btnClear->setText(QCoreApplication::translate("HostInfo", "\346\270\205\351\231\244\346\226\207\346\234\254", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HostInfo: public Ui_HostInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOSTINFO_H
