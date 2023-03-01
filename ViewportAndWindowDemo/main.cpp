#include "ViewportAndWindowDemo.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ViewportAndWindowDemo w;
    w.show();
    return a.exec();
}
