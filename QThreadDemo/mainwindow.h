#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Executor.h"
#include "IRunable.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Executor;
class IRunable;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_start_clicked();

    void on_pushButton_pause_clicked();

    void on_pushButton_stop_clicked();

    void on_pushButton_resume_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Executor* executor;
    QList<IRunable*> runableList;
};
#endif // MAINWINDOW_H
