#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qDebug() << QSqlDatabase::drivers();

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("rotor");
    db.setPassword("robot-soul");
    db.setDatabaseName("rotor");
    if (!db.open()){
        QMessageBox::warning(this, "fail", db.lastError().text());
        return;
    }else{
        qDebug() << "db is open";
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

