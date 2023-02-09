#include "QDiceThread.h"

QDiceThread::QDiceThread(QObject *parent)
    : QThread{parent}
{

}

void QDiceThread::diceBegin(){ // 开始
    m_paused = false;
}

void QDiceThread::dicePause(){ // 暂停
    m_paused = true;
}

void QDiceThread::stopThread(){
    m_stop = true;
}

void QDiceThread::run(){
    m_stop = false;
    m_seq = 0;

   // 设置随机种子
    srand(QTime::currentTime().msec());
    while(!m_stop){
        if(!m_paused){ // 未暂停
            m_diceValue = (rand() % 6) + 1;
            m_seq++;
            emit newValue(m_seq,m_diceValue);
        }
        msleep(500);
    }

    quit();

}
