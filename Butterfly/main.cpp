#include <QtWidgets/QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "ButterflyItem.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 场景：管理视图/图元
    QGraphicsScene* scene = new QGraphicsScene;
    scene->setSceneRect(QRectF(-200, -200, 400, 400));

    // 图元
    ButterflyItem* butterfly = new ButterflyItem;
    butterfly->setPos(-100, 0);

    // 将图元加入到场景中
    scene->addItem(butterfly);

    // 视图
    QGraphicsView* view = new QGraphicsView;
    // 设置视图的场景
    view->setScene(scene);

    view->resize(400, 400);

    // 视图用于显示图元
    view->show();
   
    return a.exec();
}
