#include "mainwindow.h"

#include <QApplication>
#include <QStandardItemModel>
#include <QTableView>
#include <QFile>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QStandardItemModel model;
    QTableView tableView;
    tableView.setModel(&model);

    model.setHorizontalHeaderItem(0,new QStandardItem("NAME"));
    model.setHorizontalHeaderItem(1,new QStandardItem("DATE"));
    model.setHorizontalHeaderItem(2,new QStandardItem("AGE"));
    model.setHorizontalHeaderItem(3,new QStandardItem("NAME"));

//    QFile file("test.txt");
//    if(file.open(QFile::ReadOnly|QFile::Text)){
//        QTextStream stream(&file);
//        QString line;
//        //model.removeRows(0,model.rowCount(QModelIndex()),QModelIndex());
//        int row = 0;
//        do{
//            line = stream.readLine();
//            if(!line.isEmpty()){
//                model.insertRows(row,1);
//                QStringList pieces = line.split(",",QString::SkipEmptyParts);

//                model.setData(model.index(row, 0), pieces.value(0));
//                model.setData(model.index(row, 1), pieces.value(1));
//                model.setData(model.index(row, 2), pieces.value(2));
//                model.setData(model.index(row, 3), pieces.value(3));
//                row++;
//            }
//        }while(!line.isEmpty());
//        file.close();
//    }
    tableView.setWindowTitle("Delegate");
    tableView.show();
//    MainWindow w;
//    w.show();

    return a.exec();
}
