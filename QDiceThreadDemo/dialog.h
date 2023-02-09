#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "QDiceThread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;
    QDiceThread thread;

private slots:
    void onThreadStarted();
    void onThreadFinished();
    void onThreadNewValue(int seq,int diceValue);

    void on_btnStartThread_clicked();
    void on_btnStopThread_clicked();

    void on_btnDiceBegin_clicked();
    void on_btnDiceEnd_clicked();

    void on_btnClear_clicked();

protected:
    void closeEvent(QCloseEvent* event);
};
#endif // DIALOG_H