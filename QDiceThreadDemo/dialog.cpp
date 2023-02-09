#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(&thread,&QDiceThread::started,this,&Dialog::onThreadStarted);
    connect(&thread,&QDiceThread::finished,this,&Dialog::onThreadFinished);
    connect(&thread,&QDiceThread::newValue,this,&Dialog::onThreadNewValue);
}

void Dialog::onThreadStarted(){
    ui->LabA->setText("启动");
}

void Dialog::onThreadFinished(){
    ui->LabA->setText("结束");
}

void Dialog::onThreadNewValue(int seq,int diceValue){ // 线程值
    QString str = QString::asprintf("第%d次投骰子，显示点数:%d",seq,diceValue);
    ui->plainTextEdit->appendPlainText(str);

    QPixmap  pic;
    int width = ui->LabPic->width();
    int height = ui->LabPic->height();
    QString filename = QString::asprintf(":/dice/images/d%d.png",diceValue);
    pic.load(filename);
    pic = pic.scaled(width,height,Qt::AspectRatioMode::KeepAspectRatio);
    ui->LabPic->setPixmap(pic);
}

void Dialog::closeEvent(QCloseEvent *event)
{
    if(thread.isRunning()){
        thread.stopThread();
        thread.wait();
    }

    accept();
}

void Dialog::on_btnStartThread_clicked()
{
    thread.start();
    ui->btnStartThread->setEnabled(false);
    ui->btnStopThread->setEnabled(true);

    ui->btnDiceBegin->setEnabled(true);
    ui->btnDiceEnd->setEnabled(false);
}

void Dialog::on_btnDiceBegin_clicked()
{
    thread.diceBegin();

    ui->btnDiceBegin->setEnabled(false);
    ui->btnDiceEnd->setEnabled(true);
}

void Dialog::on_btnDiceEnd_clicked()
{
     thread.dicePause();

     ui->btnDiceBegin->setEnabled(true);
     ui->btnDiceEnd->setEnabled(false);
}

void Dialog::on_btnClear_clicked()
{
    ui->plainTextEdit->clear();
}

void Dialog::on_btnStopThread_clicked() // 结束线程
{
    thread.stopThread();

    ui->btnDiceBegin->setEnabled(false);
    ui->btnDiceEnd->setEnabled(false);
    ui->btnStartThread->setEnabled(true);
    ui->btnStopThread->setEnabled(false);
}

Dialog::~Dialog()
{
    delete ui;
}

