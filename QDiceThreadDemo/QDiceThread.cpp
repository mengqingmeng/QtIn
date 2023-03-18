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

int QDiceThread::diceValue()
{
    return m_diceValue;
}

void QDiceThread::run(){

    // 初始化标识
    m_stop = false;
    m_seq = 0;

   // 设置随机种子
    srand(QTime::currentTime().msec());
    while(!m_stop){ // 未停止
        if(!m_paused){ // 未暂停
            m_diceValue = (rand() % 6) + 1; // 1-6 随机数
            m_seq++; // 次数
            emit newValue(m_seq,m_diceValue);
        }
        msleep(500);
    }

    quit();

}
