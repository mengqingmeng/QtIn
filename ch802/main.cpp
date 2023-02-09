#include "mainwindow.h"
#include "ModelEx.h"
#include <QApplication>
#include <QTableView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ModelEx modelEx;
    QTableView view;

    view.setModel(&modelEx);
    view.resize(400,400);
    view.show();

//    MainWindow w;
//    w.show();
    return a.exec();
}
