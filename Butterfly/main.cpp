#include <QtWidgets/QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "ButterflyItem.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // ������������ͼ/ͼԪ
    QGraphicsScene* scene = new QGraphicsScene;
    scene->setSceneRect(QRectF(-200, -200, 400, 400));

    // ͼԪ
    ButterflyItem* butterfly = new ButterflyItem;
    butterfly->setPos(-100, 0);

    // ��ͼԪ���뵽������
    scene->addItem(butterfly);

    // ��ͼ
    QGraphicsView* view = new QGraphicsView;
    // ������ͼ�ĳ���
    view->setScene(scene);

    view->resize(400, 400);

    // ��ͼ������ʾͼԪ
    view->show();
   
    return a.exec();
}
