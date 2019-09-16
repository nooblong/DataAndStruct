//
// Created by lyl on 2019/9/16.
//

#ifndef DATAANDSTRUCT_LIST_H
#define DATAANDSTRUCT_LIST_H

template<class T> class List{
public:
    virtual void clear() = 0;
    virtual bool empty()const = 0;
    virtual int size()const = 0;
    virtual void insert(int i, const T &value) = 0;
    virtual void remove(int i) = 0;
    virtual int search(const T &value) const = 0;
    virtual T visit(int i)const = 0;
    virtual void traverse()const = 0;
    virtual void inverse() = 0;
    virtual ~List() {};
};




#endif //DATAANDSTRUCT_LIST_H
