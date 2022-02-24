#include "mainwindow.h"
#include "ui_mainwindow.h"

const static double PI = 3.14159;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_countBtn_clicked()
{
    bool ok;
    //QString tempStr;
    QString valueStr = ui->radiusInput->text();
    double valueInt = valueStr.toDouble();
    double area = valueInt * valueInt * PI;
    ui->areaLabel2->setText(QString::number(area));
}


void MainWindow::on_radiusInput_textChanged(const QString &arg1)
{
    double valueInt = arg1.toDouble();
    double area = valueInt * valueInt * PI;
    ui->areaLabel2->setText(QString::number(area));
}

