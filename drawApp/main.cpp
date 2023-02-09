#include "mainwindow.h"

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene* scene = new QGraphicsScene;
    scene->addLine(10,10,150,300);

    QGraphicsView* view = new QGraphicsView(scene);
    view->resize(500, 500);
    view->setWindowTitle("GraphicsView");
    view->show();

    MainWindow w;
    w.show();
    return a.exec();
}
