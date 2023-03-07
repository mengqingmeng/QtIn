#include "QGraphicsViewDemo.h"

QGraphicsViewDemo::QGraphicsViewDemo(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    labelViewCord = new QLabel("View 坐标:");
    labelViewCord->setMinimumWidth(150);
    ui.statusBar->addWidget(labelViewCord);

    labelSceneCord = new QLabel("Scene 坐标:");
    labelSceneCord->setMinimumWidth(150);
    ui.statusBar->addWidget(labelSceneCord);

    labelItemCord = new QLabel("Item 坐标:");
    labelItemCord->setMinimumWidth(150);
    ui.statusBar->addWidget(labelItemCord);

    ui.graphicsView->setCursor(Qt::CrossCursor);
    ui.graphicsView->setMouseTracking(true);
    ui.graphicsView->setDragMode(QGraphicsView::RubberBandDrag);

    connect(ui.graphicsView, &QWGraphicsView::mouseMovePoint, this, [&](QPoint point) {
        labelViewCord->setText(QString::asprintf("View 坐标 %d,%d", point.x(), point.y()));
        QPointF pointScene = ui.graphicsView->mapToScene(point);
        labelSceneCord->setText(QString::asprintf("Scene 坐标 %d,%d", pointScene.x(), pointScene.y()));
    });

    connect(ui.graphicsView, &QWGraphicsView::mouseClicked, this, [&](QPoint point) {
        QPointF pointScene = ui.graphicsView->mapFromScene(point);
        QGraphicsItem* item = nullptr;
        if (scene) {
            item = scene->itemAt(pointScene, ui.graphicsView->transform());
            if (item) {
                QPointF pointItem = item->mapFromScene(pointScene);
                labelItemCord->setText(QString::asprintf("Item 坐标 %d,%d", pointItem.x(), pointItem.y()));
            }
        }
    });

    initGraphicsSystem();
}

QGraphicsViewDemo::~QGraphicsViewDemo()
{}

void QGraphicsViewDemo::initGraphicsSystem()
{
}

void QGraphicsViewDemo::resizeEvent(QResizeEvent* event)
{
}
