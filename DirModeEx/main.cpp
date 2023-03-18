#include "MainWindow.h"

#include <QApplication>
#include <QFileSystemModel>
#include <QTreeView>
#include <QListView>
#include <QTableView>
#include <QAbstractItemView>
#include <QSplitter>

/// MODEL 和 VIEW联动
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFileSystemModel model;
    // 设置根目录
    model.setRootPath(QDir::currentPath());

    QTreeView tree;
    QListView list;
    QTableView table;

    tree.setModel(&model);
    list.setModel(&model);
    table.setModel(&model);

    tree.setSelectionMode(QAbstractItemView::MultiSelection);
    list.setSelectionMode(tree.selectionMode());
    table.setSelectionModel(tree.selectionModel());

    QObject::connect(&tree,&QTreeView::expanded,&list,&QListView::setRootIndex);

    QObject::connect(&tree,&QTreeView::expanded,&table,&QTableView::setRootIndex);

    QSplitter* splitter = new QSplitter;
    splitter->addWidget(&tree);
    splitter->addWidget(&list);
    splitter->addWidget(&table);
    splitter->setWindowTitle(QObject::tr("Model/View"));
    //splitter->show();
    MainWindow w;
    w.show();
    return a.exec();
}
