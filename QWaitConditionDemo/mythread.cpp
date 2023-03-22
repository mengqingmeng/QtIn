#include "mythread.h"

QMutex m_mutex;
QWaitCondition m_waitCondition;
int seq = 0;
int diceValue = 0;

// 生产者
ProducerThread::ProducerThread(QObject *parent)
    : QThread{parent}
{

}

void ProducerThread::stopThread()
{
    m_stop = true;
}

void ProducerThread::startThread()
{
    m_stop = false;
}

void ProducerThread::run()
{
    m_stop = false;
    seq = 0;
    diceValue = 0;
    while(!m_stop){
        m_mutex.lock();
        diceValue = QRandomGenerator::global()->bounded(1,7);
        seq++;
        m_mutex.unlock();
        m_waitCondition.wakeAll(); // 唤醒别的线程，有新的数据了。
        QThread::msleep(500);
    }
}

// 消费者
ConsumerThread::ConsumerThread(QObject *parent)
    : QThread{parent}
{

}

void ConsumerThread::stopThread()
{
    m_stop = true;
}

void ConsumerThread::startThread()
{
    m_stop = false;
}

void ConsumerThread::run()
{
    m_stop = false;
    while(!m_stop){
        m_mutex.lock();
        m_waitCondition.wait(&m_mutex);
        emit newValue(seq,diceValue);
        m_mutex.unlock();
    }
}
