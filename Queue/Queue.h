//
// Created by lyl on 2019/10/15.
//

#ifndef DATAANDSTRUCT_QUEUE_H
#define DATAANDSTRUCT_QUEUE_H

template<class T>
class Queue {
public:
    virtual bool empty() const = 0;

    virtual void clear() = 0;

    virtual int size() const = 0;

    virtual void enQueue(const T &x) = 0;

    virtual T deQueue() = 0;

    virtual T getHead() const = 0;

    virtual ~Queue(){}
};

#endif //DATAANDSTRUCT_QUEUE_H
