#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setPalette(QPalette(Qt::white));

    // 设备被包含窗口是否使用绘制背景参数
    //setAutoFillBackground(true);
    resize(600, 400);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::TextAntialiasing);

    // 5角星
    qreal R = 100;
    const qreal PI = 3.14159;
    qreal deg = PI* (72.0 / 180); // 五角星，每个角72度(需转为弧度)。
    QPoint points[5] = {
        QPoint(R,0),
        QPoint(R * std::cos(deg),R * std::sin(deg)),
        QPoint(R * std::cos(2 * deg),R * std::sin(2 * deg)),
        QPoint(R * std::cos(3 * deg),R * std::sin(3 * deg)),
        QPoint(R * std::cos(4 * deg),R * std::sin(4 * deg))
    };

    // 字体
    QFont font;
    font.setPointSize(12);
    font.setBold(true);
    painter.setFont(font);

    // 画笔
    QPen pen;
    pen.setWidth(2);
    pen.setColor(Qt::blue);
    pen.setStyle(Qt::SolidLine);
    pen.setCapStyle(Qt::FlatCap);
    pen.setJoinStyle(Qt::BevelJoin);
    painter.setPen(pen);

    // 毛刷
    QBrush brush;
    brush.setColor(Qt::yellow);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);

    QPainterPath starPath;
    starPath.moveTo(points[0]);
    starPath.lineTo(points[2]);
    starPath.lineTo(points[4]);
    starPath.lineTo(points[1]);
    starPath.lineTo(points[3]);
    starPath.closeSubpath();

    painter.save(); // 保存坐标状态？

    // 需要移动一下，不然显示不全
    painter.translate(100, 120); 
    // 顶点标识
    starPath.addText(points[0], font, "0");
    starPath.addText(points[1], font, "1");
    starPath.addText(points[2], font, "2");
    starPath.addText(points[3], font, "3");
    starPath.addText(points[4], font, "4");
    // 画路径
    painter.drawPath(starPath);

    painter.drawText(0, 0, "S1");

    // 恢复坐标状态
    painter.restore(); // 如果不恢复，会在上一次的操作上叠加
    painter.translate(300, 200);
    painter.scale(0.8,0.8);
    painter.rotate(90);
    painter.drawPath(starPath);
    painter.drawText(0, 0, "S2");

    painter.resetTransform(); // 恢复所有的坐标变换
    painter.translate(500, 120);
    painter.rotate(-145);
    painter.drawPath(starPath);
    painter.drawText(0, 0, "S3");
}

