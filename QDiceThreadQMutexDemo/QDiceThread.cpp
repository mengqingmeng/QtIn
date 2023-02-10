#include "QDiceThread.h"

QDiceThread::QDiceThread(QObject *parent)
    : QThread{parent}
{

}

void QDiceThread::run(){
    m_stop = false;
    m_diceValue = 0;
    m_seq = 0;

    srand(QTime::currentTime().msec());  // 随机数种子
    while(!m_stop){
        if(!m_paused){
            mutex.lock();
            m_diceValue = rand() % 6 + 1;
            m_seq ++;
            mutex.unlock();
        }

        QThread::msleep(500);
    }
}

bool QDiceThread::diceValue(int* seq,int* diceValue){
    if(mutex.tryLock() && !m_stop && !m_paused){
        if(seq)
            *seq = m_seq;
        if(diceValue)
            *diceValue = m_diceValue;
        mutex.unlock();
        return true;
    }

    return false;
}

void QDiceThread::resume()
{
    m_paused = false;
}

void QDiceThread::pause(){
    m_paused = true;
}

void QDiceThread::stopThread(){
    m_stop = true;
}
