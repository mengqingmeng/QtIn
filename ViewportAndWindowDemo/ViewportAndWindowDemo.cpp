#include "ViewportAndWindowDemo.h"

ViewportAndWindowDemo::ViewportAndWindowDemo(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

ViewportAndWindowDemo::~ViewportAndWindowDemo()
{}

void ViewportAndWindowDemo::paintEvent(QPaintEvent * event)
{
    QPainter painter(this);

    int W = width();
    int H = height();

    int side = qMin(W, H);
    
    // 区域
    QRect rect((W - side) / 2, (H - side) / 2, side, side);
    painter.drawRect(rect);

    // 设置视口
    painter.setViewport(rect);

    // 设置窗口
    painter.setWindow(-100, -100, 200, 200);

    painter.setRenderHint(QPainter::Antialiasing);

    QPen pen;
    pen.setColor(Qt::red);
    pen.setStyle(Qt::SolidLine);
    painter.setPen(pen);

    QLinearGradient linearGrad(0, 0, 100, 0);
    linearGrad.setColorAt(0, Qt::yellow);
    linearGrad.setColorAt(1, Qt::green);
    linearGrad.setSpread(QGradient::PadSpread);
    painter.setBrush(linearGrad);

    // 设置符合模式
    //painter.setCompositionMode(QPainter::RasterOp_NotSourceXorDestination);
    //painter.setCompositionMode(QPainter::CompositionMode_Difference);
    painter.setCompositionMode(QPainter::CompositionMode_Exclusion);

    for (int i = 0; i < 36; i++) {
        painter.drawEllipse(QPoint(50, 0), 50, 50);
        painter.rotate(10);
    }
}
