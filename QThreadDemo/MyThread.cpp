#include "MyThread.h"
#include <QDebug>

MyThread::MyThread(QObject *parent)
    : QThread(parent),
      pauseFlag(false),
      stopFlag(false)
{

}

MyThread::~MyThread()
{
    stop();
}

/**
 * @brief MyThread::state
 * 获取线程状态
 * @return 状态
 */
MyThread::State MyThread::state() const
{
    State s = Stoped;
    if (!QThread::isRunning())
    {
        s = Stoped;
    }
    else if (QThread::isRunning() && pauseFlag)
    {
        s = Paused;
    }
    else if (QThread::isRunning() && (!pauseFlag))
    {
        s = Running;
    }
    return s;
}

/**
 * @brief MyThread::start
 * 启动线程
 * @param pri 优先级
 */
void MyThread::start(Priority pri)
{
    QThread::start(pri);
}

/**
 * @brief MyThread::stop
 * 停止线程
 */
void MyThread::stop()
{
    if (QThread::isRunning())
    {
        stopFlag = true;
        condition.wakeAll();
        QThread::quit();
        QThread::wait();
    }
}

/**
 * @brief MyThread::pause
 * 暂停线程
 */
void MyThread::pause()
{
    if (QThread::isRunning())
    {
        pauseFlag = true;
    }
}

/**
 * @brief MyThread::resume
 * 继续线程
 */
void MyThread::resume()
{
    if (QThread::isRunning())
    {
        pauseFlag = false;
        condition.wakeAll();
    }
}

/**
 * @brief MyThread::run
 * 线程函数，此函数不允许被重写。
 * 子类应该重写process()。
 */
void MyThread::run()
{
    qDebug() << "enter thread : " << QThread::currentThreadId();

    while (!stopFlag)
    {

        process();
        if (pauseFlag)
        {
            mutex.lock();
            condition.wait(&mutex);
            mutex.unlock();
        }
    }
    pauseFlag = false;
    stopFlag = false;

    qDebug() << "exit thread : " << QThread::currentThreadId();
}
