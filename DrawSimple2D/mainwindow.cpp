#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::paintEvent(QPaintEvent *)
{
    // 画板
    QPainter painter(this);

    // 矩形
    QRectF rect(10,10,90,60);

    // 画矩形、直线、椭圆
    painter.drawRect(rect);
    painter.drawLine(QPointF(10,10),QPointF(100,70));
    painter.drawEllipse(rect);

    // 画笔
    QPen pen;
    pen.setColor(QColor(255,0,0));
    pen.setStyle(Qt::PenStyle::DashLine);

    // 画刷
    QBrush brush(QColor(0,0, 0, 125));
    brush.setStyle(Qt::BrushStyle::Dense7Pattern);

    painter.setBrush(brush);
    painter.setPen(pen);
    QRectF rect2(100,100,400,300);
    painter.drawRect(rect2);
}

