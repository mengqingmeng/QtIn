#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "qmythread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;
    QThreadDAQ threadProducer; // 生产者
    QThreadShow threadConsumer; // 消费者

    void closeThreads();

public slots:
    void onConsumerNewValue(int* data,int count,int bufNo);

protected:
    void closeEvent(QCloseEvent* event);
};
#endif // DIALOG_H
