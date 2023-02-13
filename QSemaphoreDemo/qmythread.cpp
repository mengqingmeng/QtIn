#include "qmythread.h"
#include <QSemaphore>

const int BufferSize = 8;

int buffer1[BufferSize];
int buffer2[BufferSize];

int curBuf = 1;// 当前使用的缓冲区
int bufNo = 0; // 缓冲区的序号（累计的缓冲区个数）

size_t counter = 0; // 数据数量计数

QSemaphore emptyBufs(2); // 可写入的缓冲区个数
QSemaphore fullBufs;    // 可读取的缓冲区个数

void QThreadDAQ::run(){
    m_stop = false;
    bufNo = 0;
    curBuf = 1;
    counter = 0;
    fullBufs.release(fullBufs.available());
    // 保证开始时，emptyBufs中有2个空间，保证两个缓冲区可写。
    int n = emptyBufs.available();
    if(n<2){
        emptyBufs.release(2-n);
    }

    while(!m_stop){
        // emptyBufs消耗一个信号
        emptyBufs.acquire();
        for(int i=0;i<BufferSize;i++){
            if(curBuf == 1){
                buffer1[i] = counter;
            }else{
                buffer2[i] = counter;
            }
            counter++;
            QThread::msleep(50);
        }

        bufNo++;

        if(curBuf == 1){
            curBuf = 2;
        }else{
            curBuf = 1;
        }

        // fullBufs获得一个信号，这个信号里有资源，就代表可以读到数据了。
        fullBufs.release();
    }
}

QThreadDAQ::QThreadDAQ()
{

}

void QThreadShow::run(){
    m_stop = false;

    // 将fullBufs消耗完。
    int n = fullBufs.available();
    if(n>0)
        fullBufs.acquire(n);

    while(!m_stop){
        fullBufs.acquire();
        int bufferData[BufferSize];
        int seq = bufNo;
        if(curBuf == 1){
            for(int i=0;i<BufferSize;i++){
                bufferData[i] = buffer2[i];
            }
        }else{
            for(int i=0;i<BufferSize;i++){
                bufferData[i] = buffer1[i];
            }
        }

        emptyBufs.release();

        emit newValue(bufferData,BufferSize,seq);
    }
}

QThreadShow::QThreadShow()
{

}
