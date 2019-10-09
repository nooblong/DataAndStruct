//
// Created by lyl on 2019/10/9.
//

#ifndef DATAANDSTRUCT_DSEQSTACK_H
#define DATAANDSTRUCT_DSEQSTACK_H

#include "Stack.h"
template <class T> class dSeqStack : public Stack<T>{
private:
    int maxSize;
    int *data;
    int top[2];
    void resize();

public:
    dSeqStack(int size);
    ~dSeqStack();
    void clear(int no);
    bool empty(int no);
    int size(int no);
    void push(const T &value, int no);
    bool pop(T *item, int no);
    T getTop(int no) const ;
};

template<class T>
void dSeqStack<T>::resize() {

}

template<class T>
dSeqStack<T>::dSeqStack(int size) {

}

template<class T>
dSeqStack<T>::~dSeqStack() {

}

template<class T>
void dSeqStack<T>::clear(int no) {

}

template<class T>
bool dSeqStack<T>::empty(int no) {
    return false;
}

template<class T>
int dSeqStack<T>::size(int no) {
    return 0;
}

template<class T>
void dSeqStack<T>::push(const T &value, int no) {

}

template<class T>
bool dSeqStack<T>::pop(T *item, int no) {
    return false;
}

template<class T>
T dSeqStack<T>::getTop(int no) const {
    return nullptr;
}

#endif //DATAANDSTRUCT_DSEQSTACK_H
