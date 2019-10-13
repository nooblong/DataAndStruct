//
// Created by lyl on 2019/10/8.
//

#ifndef DATAANDSTRUCT_STACK_H
#define DATAANDSTRUCT_STACK_H

template <class T> class Stack{
public:
    virtual bool empty() const = 0;
    virtual int size() const = 0;
    virtual void push(const T &x) = 0;
    virtual T pop() = 0;
    virtual T getTop() const = 0;
    virtual void clear() = 0;
    virtual ~Stack() {}
};

#endif //DATAANDSTRUCT_STACK_H
