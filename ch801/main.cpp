#include "mainwindow.h"

#include <QApplication>
#include <QAbstractItemModel>
#include <QAbstractItemView>
#include <QItemSelectionModel>
#include <QFileSystemModel>
#include <QTreeView>
#include <QListView>
#include <QTableView>
#include <QSplitter>
#include <QModelIndex>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFileSystemModel model;

    QTreeView tree;
    QListView list;
    QTableView table;
    tree.setModel(&model);
    list.setModel(&model);
    table.setModel(&model);

    //tree.setSelectionModel(QAbstractItemView::MultiSelection);

    QObject::connect(&tree,&QTreeView::doubleClicked,&list,[](){

    });

    QObject::connect(&tree,&QTreeView::doubleClicked,&table,[](){

    });

    QSplitter *splitter = new QSplitter;
    splitter->addWidget(&tree);
    splitter->addWidget(&list);
    splitter->addWidget(&table);

    splitter->setWindowTitle(QString::fromLocal8Bit("Modal/View"));
    splitter->show();

//    MainWindow w;
//    w.show();
    return a.exec();
}
