//
// Created by lyl on 2019/9/16.
//

#ifndef DATAANDSTRUCT_SEQLIST_H
#define DATAANDSTRUCT_SEQLIST_H

#include <iostream>
#include "List.h"
#include "../Exception.h"

template <class elemType>
class SeqLIst : public List<elemType> {
private:
elemType *data;
int curLength;

    void resize();
public:
    void clear(){curLength = 0;}
    bool empty()const { return curLength==0;}
    SeqLIst(int initSize = 10);
    SeqLIst(SeqLIst & sl);
    ~SeqLIst(){delete [] data;}
    int size()const { return curLength;}
    void traverse()const ;
    void inverse();
    void insert(int i, const elemType &value);
    void remove(int i);
    int search(const elemType &value) const ;
    elemType visit(int i)const ;
    bool Union(SeqLIst<elemType> &B);


    int maxSize;
};
template <class elemType>
SeqLIst<elemType>::SeqLIst(int initSize) {
    if(initSize <= 0) throw badSize();
    maxSize = initSize;
    data = new elemType[maxSize];
    curLength = 0;
}

template<class elemType>
SeqLIst<elemType>::SeqLIst(SeqLIst &sl) {
    maxSize = sl.maxSize;
    curLength = sl.curLength;
    data = new elemType[maxSize];
    for (int i = 0; i < curLength; ++i) {
        data[i] = sl.data[i];
    }
}

template<class elemType>
void SeqLIst<elemType>::traverse() const {
    if (empty()) std::cout<<"is empty"<<std::endl;
    else{
        std::cout<<"Output element: \n";
        for (int i = 0; i < curLength; ++i) {
            std::cout<<data[i]<<" ";
        }
        std::cout<<std::endl;
    }
}

template<class elemType>
void SeqLIst<elemType>::inverse() {
    elemType tmp;
    for (int i = 0; i < curLength / 2; i++) {
        tmp = data[i];
        data[i] = data[curLength-i-1];
        data[curLength-i-1] = tmp;
    }
}

template<class elemType>
void SeqLIst<elemType>::insert(int i, const elemType &value) {
    if (i < 0 || i > curLength) throw outOfRange();
    if (curLength == maxSize) resize();
    for (int j = curLength; j > i ; j--) {
        data[j] = data[j - 1];
    }
        data[i] = value;
        ++curLength;
}

template<class elemType>
void SeqLIst<elemType>::remove(int i) {
    if(i < 0 || i > curLength -1) throw outOfRange();
    for (int j = i; j < curLength ; j++) {
        data[j] = data[j+1];
    }
    --curLength;
}

template<class elemType>
int SeqLIst<elemType>::search(const elemType &value) const {
    for (int i = 0; i < curLength; ++i) {
        if (value == data[i])
            return i;
    }
    return -1;
}

template<class elemType>
elemType SeqLIst<elemType>::visit(int i) const {
    return data[i];
}

template<class elemType>
void SeqLIst<elemType>::resize() {
    elemType *p = data;
    maxSize *=2;
    data = new elemType[maxSize];
    for (int i = 0; i < curLength; ++i) {
        data[i] = p[i];
    }
    delete [] p;
}

template<class elemType>
bool SeqLIst<elemType>::Union(SeqLIst<elemType> &B) {
    //复杂度O(m+n)
    int m,n,k,i,j;
    m = this->curLength;//长度
    n = B.curLength;//长度
    k = m+n-1;//结果线性表的工作指针下标
    i = m-1;//线性表A的工作指针下标
    j = n-1;//线性表B的工作指针下标
    if (m+n > this->maxSize){
        resize();
    }
    while (i>=0 && j >= 0){
        if (data[i] >= B.data[j])
            data[k--] = data[i--];
        else
            data[k--] = B.data[j--];
    }
    while (j>=0){
        data[k--] = B.data[j--];
    }
    curLength = m + n;
    return true;

}


#endif //DATAANDSTRUCT_SEQLIST_H
