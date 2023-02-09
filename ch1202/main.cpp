#include "mainwindow.h"

#include <QApplication>
#include <QThread>
#include <QSemaphore>
#include <stdio.h>
#include <iostream>

const int DataSize = 1000;
const int BufferSize = 80;

int buffer[BufferSize];
QSemaphore freeBytes(BufferSize);
QSemaphore usedBytes(0);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    std::cout << "data size:" << DataSize << std::endl;
    return a.exec();
}
