#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QWaitCondition>
#include <QMutex>
#include <QRandomGenerator>

class ConsumerThread : public QThread
{
    Q_OBJECT
public:
    explicit ConsumerThread(QObject *parent = nullptr);
    void stopThread();
    void startThread();

private:
    // 暂停工作标识
    bool m_stop = false;

protected:
    void run() override;

signals:
    // 产生新值时的信号
    void newValue(int seq,int value);

};

/// 生产者线程
class ProducerThread : public QThread
{
    Q_OBJECT
public:
    explicit ProducerThread(QObject *parent = nullptr);
    void stopThread();
    void startThread();

private:
    // 暂停工作标识
    bool m_stop = false;

protected:
    void run() override;

};

#endif // MYTHREAD_H
