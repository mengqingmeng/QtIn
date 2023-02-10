#ifndef QDICETHREAD_H
#define QDICETHREAD_H

#include <QThread>
#include <QMutex>
#include <QTime>

class QDiceThread : public QThread
{
    Q_OBJECT
public:
    explicit QDiceThread(QObject *parent = nullptr);
    bool diceValue(int* seq,int* diceValue);
    /**
     * @brief start 恢复
     */
    void resume();
    /**
     * @brief pause 暂停
     */
    void pause();

    /**
     * @brief stopThread 停止线程
     */
    void stopThread();
private:
    int m_seq=0;
    int m_diceValue;
    bool m_paused=true;
    bool m_stop;
    QMutex mutex; // 互斥锁
protected:
    void run() override;
};

#endif // QDICETHREAD_H
