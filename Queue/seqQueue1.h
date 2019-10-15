//
// Created by lyl on 2019/10/15.
//

#ifndef DATAANDSTRUCT_SEQQUEUE1_H
#define DATAANDSTRUCT_SEQQUEUE1_H

#include <iostream>
#include "Queue.h"
#include "../Exception.h"

template<class T>
class seqQueue : public Queue<T> {
private:
    T *data;
    int front, rear;
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
    try {
        if (initSize <= 0) throw badSize();
    } catch (badSize e) {
        printf(e.what());
        cout << " in line 62" << endl;
        return;
    }
    data = new T[initSize];
    maxSIze = initSize;
    front = rear = -1;
}

template<class T>
void seqQueue<T>::resize() {
    std::cout << "resize()" << std::endl;
    T *p = data;
    data = new T[maxSIze * 2];
    for (int i = 1; i < size(); ++i) {
        //在数组中，front 可能不是在索引为0的位置，相对于i有一个偏移量
        data[i] = p[(front + i) % maxSIze];
        front = 0;
        rear = size();
        maxSIze = maxSIze * 2;
        delete[]p;
    }
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
    return ((rear-front+maxSIze)%maxSIze);
}

template<class T>
void seqQueue<T>::enQueue(const T &x) {
    if ((rear + 1) % maxSIze == front) {
        //队列为满{
        cout<<"queue is full"<<endl;
        resize();
    }
    rear = (rear + 1) % maxSIze;
    data[rear] = x;
}

template<class T>
T seqQueue<T>::deQueue() {
    if (empty()) throw outOfRange();
    front = (front + 1) % maxSIze;//front的元素在front+1
    return data[front];
}

template<class T>
T seqQueue<T>::getHead() const {
    if (empty()) throw outOfRange();
    return data[(front + 1) % maxSIze];
}

#endif //DATAANDSTRUCT_SEQQUEUE1_H
