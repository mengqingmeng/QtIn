#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    startBtn = ui->startBtn;
    stopBtn = ui->stopBtn;
    quitBtn = ui->quitBtn;
    connect(startBtn,&QPushButton::clicked,this,&MainWindow::slotStart);
    connect(stopBtn,&QPushButton::clicked,this,&MainWindow::slotStop);
    connect(quitBtn,&QPushButton::clicked,this,&MainWindow::close);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotStart()
{
    for(int i=0;i<MAXSIZE;i++){
        workThread[i] = new WorkThread();
    }

    for(int i=0;i<MAXSIZE;i++){
        workThread[i]->start();
    }

    startBtn->setEnabled(false);
    stopBtn->setEnabled(true);
}

void MainWindow::slotStop()
{
    for(int i=0;i<MAXSIZE;i++){
        workThread[i]->terminate();
        workThread[i]->wait();
    }

    startBtn->setEnabled(true);
    stopBtn->setEnabled(false);
}

