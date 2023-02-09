#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QThread>
#include <atomic>
#include <QMutex>
#include <QWaitCondition>

class MyThread : public QThread{
    Q_OBJECT

public:
    MyThread(QObject* parent = nullptr);
    ~MyThread() override;

    enum State{
        Stoped,Running,Paused
    };

    State state() const;

public slots:
    void start(QThread::Priority pri = InheritPriority);
    void stop();
    void pause();
    void resume();

protected:
    virtual void run() override;
    /**
     * @brief process 纯虚函数，子类必须重写。此方法为执行的任务
     */
    virtual void process() = 0;

private:
    std::atomic_bool pauseFlag;   ///<暂停标识
    std::atomic_bool stopFlag;   ///<停止标识
    QMutex mutex;   ///<锁，用于实现线程暂停
    QWaitCondition condition;  ///<等待条件，用于实现线程暂停
};

#endif // MYTHREAD_H
