#ifndef QMYTHREAD_H
#define QMYTHREAD_H
#include <QThread>

// 生产者
class QThreadDAQ : public QThread{
    Q_OBJECT
private :
    bool m_stop = false;
protected:
    void run() override;
public:
    QThreadDAQ();
    void stopThread();
};

// 消费者
class QThreadShow:public QThread{
    Q_OBJECT
private :
    bool m_stop = false;
protected:
    void run() override;
public:
    QThreadShow();

signals:
    /**
     * @brief newValue 从生产者那里读取数据，通过此信号传输给界面
     * @param data  数据
     * @param count 数量
     * @param seq   序号
     */
    void newValue(int *data,int count,int seq);

};

#endif // QMYTHREAD_H
