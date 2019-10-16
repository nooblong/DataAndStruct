//
// Created by lyl on 2019/10/16.
// 另一种实现
//

#ifndef DATAANDSTRUCT_SEQQUEUE2_H
#define DATAANDSTRUCT_SEQQUEUE2_H

#include <iostream>
#include "Queue.h"
#include "../Exception.h"

template<class T>
class seqQueue : public Queue<T> {
private:
    T *data;
    int front;
    int rear;//指向最后一个的下一个
public:

    void resize();

    int maxSIze;

    seqQueue(int initSize = 100);

    ~seqQueue() { delete[] data; }

    void clear() { front = rear = -1; }

    bool empty() const;

    bool full() const;

    int size() const;

    void enQueue(const T &x);

    T deQueue();

    T getHead() const;
};

template<class T>
seqQueue<T>::seqQueue(int initSize) {
    data = new T[initSize];
    maxSIze = initSize;
    front = rear = 0;
}

template<class T>
void seqQueue<T>::resize() {
    std::cout << "resize()" << std::endl;
    T *p = data;
    data = new T[maxSIze * 2];
    for (int i = 0; i < maxSIze; ++i) {
        data[i] = p[(front + i) % maxSIze];
    }
    front = 0;
    rear = maxSIze-1;
    maxSIze = maxSIze * 2;
    delete[]p;

}

template<class T>
bool seqQueue<T>::empty() const {
    return front == rear;
}

template<class T>
bool seqQueue<T>::full() const {
    return (rear + 1) % maxSIze == front;
}

template<class T>
int seqQueue<T>::size() const {
    return ((rear - front + maxSIze) % maxSIze);
}

template<class T>
void seqQueue<T>::enQueue(const T &x) {
    if (full()) {
        cout << "queue is full" << endl;
        resize();
    }
    data[rear] = x;
    rear = (rear + 1) % maxSIze;
}

template<class T>
T seqQueue<T>::deQueue() {
    T result;
    if (empty()) throw outOfRange();
    result = data[front];
    front = (front + 1) % maxSIze;//front的元素在front+1
    return result;
}

template<class T>
T seqQueue<T>::getHead() const {
    if (empty()) throw outOfRange();
    return data[(front + 1) % maxSIze];
}

#endif //DATAANDSTRUCT_SEQQUEUE2_H
