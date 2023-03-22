#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QMenu>
#include <QAction>
#include <QSplitter>
#include <QMenuBar>
#include <QTableView>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void createAction();
    void createMenu();
    void setupModel();
    void setupView();

private:
    Ui::MainWindow *ui;
    QMenu* fileMenu;
    QAction* openAct;
    QStandardItemModel* model;
    QTableView* table;
    QSplitter* splitter;

    // 打开文件，解析内容到model中
    void openFile(QString);
};
#endif // MAINWINDOW_H
