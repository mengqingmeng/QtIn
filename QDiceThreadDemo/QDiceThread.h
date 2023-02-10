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
    /**
     * @brief m_seq 骰子序号（第m_seq次投骰子）
     */
    int m_seq = 0;

    /**
     * @brief m_diceValue 骰子点数（当前投骰子所得到的点数）
     */
    int m_diceValue = 0;

    /**
     * @brief m_paused 暂停标识，初始情况是暂停的
     */
    bool m_paused = true;

    /**
     * @brief m_stop 停止标识
     */
    bool m_stop = false;

protected:
    void run() override;

public:
    /**
     * @brief diceBegin 开始线程，修改m_paused标识为false
     */
    void diceBegin();

    /**
     * @brief dicePause 暂停线程，修改m_paused标识为true
     */
    void dicePause();

    /**
     * @brief stopThread 停止线程，修改m_stop标识为true
     */
    void stopThread();

signals:
    /**
     * @brief newValue 当投骰子后，触发此信号
     * @param seq   当前的次数
     * @param diceValue 骰子的点数
     */
    void newValue(int seq,int diceValue);
};

#endif // QDICETHREAD_H
