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
    QPushButton *btnStartThread;
    QPushButton *btnResume;
    QPushButton *btnPause;
    QPushButton *btnStopThread;
    QPushButton *btnClear;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(458, 300);
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
        btnStartThread = new QPushButton(widget);
        btnStartThread->setObjectName("btnStartThread");

        horizontalLayout_2->addWidget(btnStartThread);

        btnResume = new QPushButton(widget);
        btnResume->setObjectName("btnResume");

        horizontalLayout_2->addWidget(btnResume);

        btnPause = new QPushButton(widget);
        btnPause->setObjectName("btnPause");

        horizontalLayout_2->addWidget(btnPause);

        btnStopThread = new QPushButton(widget);
        btnStopThread->setObjectName("btnStopThread");

        horizontalLayout_2->addWidget(btnStopThread);

        btnClear = new QPushButton(widget);
        btnClear->setObjectName("btnClear");

        horizontalLayout_2->addWidget(btnClear);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(groupBox);
        widget_2->setObjectName("widget_2");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        plainTextEdit = new QPlainTextEdit(widget_2);
        plainTextEdit->setObjectName("plainTextEdit");

        verticalLayout_2->addWidget(plainTextEdit);


        verticalLayout->addWidget(widget_2);


        horizontalLayout->addWidget(groupBox);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Dialog", "QMutex\344\272\222\346\226\245\351\207\217", nullptr));
        btnStartThread->setText(QCoreApplication::translate("Dialog", "\345\220\257\345\212\250\347\272\277\347\250\213", nullptr));
        btnResume->setText(QCoreApplication::translate("Dialog", "\350\277\220\350\241\214", nullptr));
        btnPause->setText(QCoreApplication::translate("Dialog", "\346\232\202\345\201\234", nullptr));
        btnStopThread->setText(QCoreApplication::translate("Dialog", "\345\205\263\351\227\255\347\272\277\347\250\213", nullptr));
        btnClear->setText(QCoreApplication::translate("Dialog", "\346\270\205\351\231\244\346\226\207\346\234\254", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
