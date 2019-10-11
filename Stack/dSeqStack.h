//
// Created by lyl on 2019/10/9.
//

#ifndef DATAANDSTRUCT_DSEQSTACK_H
#define DATAANDSTRUCT_DSEQSTACK_H

#include <iostream>
#include "Stack.h"
#include "../Exception.h"

template<class T>
class dSeqStack{
private:
    int *data;
    int top[2];

    void resize();

public:
    dSeqStack(int size = 100);

    ~dSeqStack(){delete []data;}

    void clear(int no);

    bool empty(int no);

    int size(int no);

    void push(const T &value, int no);

    T pop(int no);

    T getTop(int no) const;

    int maxSize;
};

template<class T>
void dSeqStack<T>::resize() {
    cout<<"resize()"<<endl;
    T *tmp = data;
    data = new T[2*maxSize];
    //0
    for (int i = 0; i < top[0]; ++i) {
        data[i+1] = tmp[i+1];
    }
    for (int j = maxSize; j > top[1]; --j) {
        data[maxSize-1] = tmp[maxSize-1];
    }
    maxSize*=2;
    delete[] tmp;
}

template<class T>
dSeqStack<T>::dSeqStack(int size) {
    if (size <= 0) throw badSize();
    data = new T[size * 2];
    maxSize = size * 2;
    top[0] = 0;
    top[1] = maxSize - 1;
}

template<class T>
void dSeqStack<T>::clear(int no) {
    if (no == 0)
        top[0] = 0;
    if (no == 1)
        top[1] = maxSize - 1;
}

template<class T>
bool dSeqStack<T>::empty(int no) {
    if (no == 0)
        return top[0] == 0;
    if (no == 1)
        return top[1] == maxSize;
    throw badSize();
}

template<class T>
int dSeqStack<T>::size(int no) {
    if (no == 0)
        return top[0];
    if (no == 1)
        return maxSize - top[1]-1;
    throw badSize();
}

template<class T>
void dSeqStack<T>::push(const T &value, int no) {
    if (top[0] == top[1])
        resize();
    if (no == 0)
        data[++top[0]] = value;
    if (no == 1)
        data[--top[1]] = value;
}

template<class T>
T dSeqStack<T>::pop(int no) {
    if (no == 0) {
        if (empty(0))
            throw outOfRange();
        return data[top[0]--];
    }
    if (no == 1) {
        if (empty(1))
            throw outOfRange();
        return data[top[1]++];
    }
    return false;
}

template<class T>
T dSeqStack<T>::getTop(int no) const {
    if (no == 0) {
        if (empty(0))
            throw outOfRange();
        return data[top[0]];
    }
    if (no == 1) {
        if (empty(1))
            throw outOfRange();
        return data[top[1]];
    }
}

#endif //DATAANDSTRUCT_DSEQSTACK_H
