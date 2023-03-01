/********************************************************************************
** Form generated from reading UI file 'Dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnStart;
    QPushButton *btnEnd;
    QPushButton *btnClear;
    QPlainTextEdit *plainTextEdit;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLabel *produceStatus;
    QLabel *label_3;
    QLabel *consumerStatus;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(400, 300);
        horizontalLayout = new QHBoxLayout(Dialog);
        horizontalLayout->setObjectName("horizontalLayout");
        groupBox = new QGroupBox(Dialog);
        groupBox->setObjectName("groupBox");
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName("verticalLayout");
        widget = new QWidget(groupBox);
        widget->setObjectName("widget");
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        btnStart = new QPushButton(widget);
        btnStart->setObjectName("btnStart");

        horizontalLayout_2->addWidget(btnStart);

        btnEnd = new QPushButton(widget);
        btnEnd->setObjectName("btnEnd");

        horizontalLayout_2->addWidget(btnEnd);

        btnClear = new QPushButton(widget);
        btnClear->setObjectName("btnClear");

        horizontalLayout_2->addWidget(btnClear);


        verticalLayout->addWidget(widget);

        plainTextEdit = new QPlainTextEdit(groupBox);
        plainTextEdit->setObjectName("plainTextEdit");

        verticalLayout->addWidget(plainTextEdit);

        widget_2 = new QWidget(groupBox);
        widget_2->setObjectName("widget_2");
        horizontalLayout_3 = new QHBoxLayout(widget_2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label = new QLabel(widget_2);
        label->setObjectName("label");

        horizontalLayout_3->addWidget(label);

        produceStatus = new QLabel(widget_2);
        produceStatus->setObjectName("produceStatus");

        horizontalLayout_3->addWidget(produceStatus);

        label_3 = new QLabel(widget_2);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        consumerStatus = new QLabel(widget_2);
        consumerStatus->setObjectName("consumerStatus");

        horizontalLayout_3->addWidget(consumerStatus);


        verticalLayout->addWidget(widget_2);


        horizontalLayout->addWidget(groupBox);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Dialog", "\344\277\241\345\217\267\351\207\217", nullptr));
        btnStart->setText(QCoreApplication::translate("Dialog", "\345\274\200\345\247\213", nullptr));
        btnEnd->setText(QCoreApplication::translate("Dialog", "\347\273\223\346\235\237", nullptr));
        btnClear->setText(QCoreApplication::translate("Dialog", "\346\270\205\351\231\244", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "\347\224\237\344\272\247\350\200\205\347\212\266\346\200\201", nullptr));
        produceStatus->setText(QString());
        label_3->setText(QCoreApplication::translate("Dialog", "\346\266\210\350\264\271\350\200\205\347\212\266\346\200\201", nullptr));
        consumerStatus->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
