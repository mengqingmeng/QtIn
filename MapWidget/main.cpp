#include "MapWidget.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MapWidget w;
    w.show();
    return a.exec();
}
