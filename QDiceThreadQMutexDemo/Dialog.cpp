#include "Dialog.h"
#include "ui_Dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    ui->btnResume->setEnabled(false);
    ui->btnPause->setEnabled(false);

    ui->btnStartThread->setEnabled(true);
    ui->btnStopThread->setEnabled(false);

    // 开始线程
    connect(ui->btnStartThread,&QPushButton::clicked,this,[&](){
        m_seq = 0;
        thread.start();

        ui->btnStartThread->setEnabled(false);
        ui->btnStopThread->setEnabled(true);

        ui->btnResume->setEnabled(true);
        ui->btnPause->setEnabled(false);
    });

    // 运行
    connect(ui->btnResume,&QPushButton::clicked,this,[&](){
        thread.resume();
        timer.start(500); // 500ms执行一次

        ui->btnResume->setEnabled(false);
        ui->btnPause->setEnabled(true);

        ui->btnStartThread->setEnabled(false);
        ui->btnStopThread->setEnabled(false);
    });


    // 暂停
    connect(ui->btnPause,&QPushButton::clicked,this,[&](){
        thread.pause();
        timer.stop();

        ui->btnResume->setEnabled(true);
        ui->btnPause->setEnabled(false);

        ui->btnStartThread->setEnabled(false);
        ui->btnStopThread->setEnabled(true);
    });

    // 停止线程
    connect(ui->btnStopThread,&QPushButton::clicked,this,[&](){
        thread.stopThread();
        thread.quit();
        thread.wait();

        ui->btnResume->setEnabled(false);
        ui->btnPause->setEnabled(false);

        ui->btnStartThread->setEnabled(true);
        ui->btnStopThread->setEnabled(false);
    });

    // 定时获取数据
    connect(&timer,&QTimer::timeout,this,[&](){
        int seq = 0,value = 0;
        bool result = thread.diceValue(&seq,&value);
        if(result){
            QString str = QString::asprintf("第%d次投骰子，显示点数:%d",seq,value);
            ui->plainTextEdit->appendPlainText(str);
        }else{
            ui->plainTextEdit->appendPlainText("**读取失败**");
        }
    });

    connect(ui->btnClear,&QPushButton::clicked,this,[&](){
        ui->plainTextEdit->clear();
    });
}

Dialog::~Dialog()
{
    delete ui;
}

