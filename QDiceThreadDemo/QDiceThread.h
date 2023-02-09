#ifndef QDICETHREAD_H
#define QDICETHREAD_H

#include <QThread>
#include <QTime>

class QDiceThread : public QThread
{
    Q_OBJECT
public:
    explicit QDiceThread(QObject *parent = nullptr);

private:
    int m_seq = 0; // 骰子序号
    int m_diceValue = 0; // 骰子总点数
    bool m_paused = true; // 暂停标识，初始情况是暂停的
    bool m_stop = false; // 停止标识
protected:
    void run() override;

public:
    void diceBegin();
    void dicePause();
    void stopThread();

signals:
    void newValue(int seq,int diceValue);
};

#endif // QDICETHREAD_H
