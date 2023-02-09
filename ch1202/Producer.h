#ifndef PRODUCER_H
#define PRODUCER_H
#include <QThread>
#include <QSemaphore>

class Producer: public QThread{
public:
    Producer();
    void run();
};

#endif // PRODUCER_H
