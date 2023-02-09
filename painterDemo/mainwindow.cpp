#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("画图"));
    this->resize(800,800);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.drawLine(80,100,650,500);
    painter.setPen(Qt::red);
    painter.drawRect(10,10,100,400);
    painter.setPen(Qt::green);

    // 反走样（抗锯齿）
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(QPen(Qt::black, 5, Qt::DashDotLine, Qt::RoundCap));
    painter.setBrush(Qt::BrushStyle::Dense7Pattern);
    painter.drawEllipse(50,150,400,200);

}

