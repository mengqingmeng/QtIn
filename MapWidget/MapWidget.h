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
    /// @brief �������е�����ת��Ϊ��ͼ����ʵ������
    /// @param point ����������
    /// @return ��ͼ����ʵ������
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
