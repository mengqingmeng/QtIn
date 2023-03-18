#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(&consumerThread,&ConsumerThread::newValue,this,[&](int seq,int diceValue){
        ui->plainTextEdit->appendPlainText(QString("第%1次掷骰子，点数为：%2").arg(seq).arg(diceValue));
    });

    connect(ui->clearThreadBtn,&QPushButton::clicked,this,[&](){
        ui->plainTextEdit->clear();
    });
}

MainWindow::~MainWindow()
{
    producerThread.stopThread();
    producerThread.quit();
    producerThread.wait();

    consumerThread.stopThread();
    consumerThread.terminate();
    consumerThread.wait();

    delete ui;
}

void MainWindow::on_startThreadBtn_clicked()
{
    if(consumerThread.isRunning()){
        consumerThread.startThread();
    }else{
        consumerThread.start();
    }

    if(producerThread.isRunning()){
        producerThread.startThread();
    }else{
        producerThread.start();
    }

    ui->startThreadBtn->setEnabled(false);
    ui->stopThreadBtn->setEnabled(true);
}


void MainWindow::on_stopThreadBtn_clicked()
{
    producerThread.stopThread();
    //producerThread.quit();
    //producerThread.wait();

    consumerThread.stopThread();
    //consumerThread.wait();

    ui->startThreadBtn->setEnabled(true);
    ui->stopThreadBtn->setEnabled(false);
}

