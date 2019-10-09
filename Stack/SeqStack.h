//
// Created by lyl on 2019/10/8.
//
#include "Stack.h"
#include "../Exception.h"

#ifndef DATAANDSTRUCT_SEQSTACK_H
#define DATAANDSTRUCT_SEQSTACK_H
using namespace std;
template <class T> class seqStack : public Stack<T> {
private:
    T *data;
    int top;
    int maxSize;
    void resize();

public:
    seqStack(int initSize = 100);
    ~seqStack(){delete [] data;}
    void clear(){top = -1;}
    bool empty() const { return top == -1;}
    int size() const { return top+1;}
    void push(const T &value);
    T pop();
    T getTop() const ;
    T getPop() const ;
};

template<class T>
void seqStack<T>::resize() {
    T *tmp = data;
    data = new T[2*maxSize];
    for (int i = 0; i < maxSize; ++i) {
        data[i] = tmp[i];
    }
    maxSize*=2;
    delete [] tmp;
}

template<class T>
seqStack<T>::seqStack(int initSize) {
    if(initSize <= 0) throw badSize();
    data = new T[initSize];
    maxSize = initSize;
    top = -1;
}

template<class T>
void seqStack<T>::push(const T &value) {
    if (top == maxSize-1) resize();
    data[++top] = value;
}

template<class T>
T seqStack<T>::pop() {
    if (empty()) throw outOfRange();
    return data[top--];
}

template<class T>
T seqStack<T>::getTop() const {
    if (empty()) throw outOfRange();
    return data[top];
}

template <class T>
T seqStack<T>::getPop() const {
    if (empty()) throw outOfRange();
    return data[top];
}


#endif //DATAANDSTRUCT_SEQSTACK_H
