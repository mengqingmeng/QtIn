#pragma once

#include <QGraphicsView>
#include <QPixMap>
#include <QLabel>
#include <QPoint>
#include <QMouseEvent>
#include <QPainter>
#include <QSlider>
#include <QGridLayout>
#include <QFrame>
#include <QFile>

class MapWidget : public QGraphicsView
{
    Q_OBJECT

public:
    MapWidget(QWidget *parent = nullptr);
    ~MapWidget();
    void readMap();
    /// @brief 将场景中的坐标转换为地图中真实的坐标
    /// @param point 场景中坐标
    /// @return 地图中真实的坐标
    QPointF mapToMap(QPointF point);

public slots:
    void slotZoom(int val);

protected:
    void drawBackground(QPainter* painter, const QPointF & rect);
    void mouseMoveEvent(QMouseEvent* event);

private:
    QPixmap map;
    qreal zoom;
    QLabel* viewCoord;
    QLabel* sceneCoord;
    QLabel* mapCoord;
    double x1, y1;
    double x2, y2;

};
