#ifndef IRUNABLE_H
#define IRUNABLE_H

/**
 * @brief The IRunable class
 * 可执行接口
 */
class IRunable
{
public:
    virtual ~IRunable() {}
    virtual void exec() = 0;
};

#endif // IRUNABLE_H
