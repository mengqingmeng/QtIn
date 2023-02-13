#include "Dialog.h"
#include "ui_Dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(&threadConsumer,&QThreadShow::newValue,this,&Dialog::onConsumerNewValue); // 消费者线程产生新数据

    // 开始
    connect(ui->btnStart,&QPushButton::clicked,this,[&](){
        threadProducer.start();
        threadConsumer.start();
        ui->produceStatus->setText("运行");
        ui->consumerStatus->setText("运行");
    });


    // 结束
    connect(ui->btnEnd,&QPushButton::clicked,this,[&](){
        closeThreads();

        ui->produceStatus->setText("停止");
        ui->consumerStatus->setText("停止");
    });

    // 清除
    connect(ui->btnClear,&QPushButton::clicked,this,[&](){
        ui->plainTextEdit->clear();
    });
}

void Dialog::onConsumerNewValue(int* data,int size,int bufNo){
    QString str = QString::asprintf("第%d个缓冲区：",bufNo);

    for(int i=0;i<size;i++){
        str+=QString::asprintf("%d, ",*data);
        data++;
    }

    str +="\n";
    ui->plainTextEdit->appendPlainText(str);
}

void Dialog::closeEvent(QCloseEvent* event){
    //closeThreads();
    accept();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::closeThreads()
{
    threadProducer.terminate(); // 强制结束。（因为有互锁，所以要强制结束。但是还是不太理解什么时候使用quit，什么时候用terminate）
    threadProducer.wait();
    threadConsumer.terminate();
    threadConsumer.wait();
}

