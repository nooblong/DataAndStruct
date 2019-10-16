//
// Created by lyl on 2019/10/16.
//

#ifndef DATAANDSTRUCT_LINKQUEUE_H
#define DATAANDSTRUCT_LINKQUEUE_H

#include "Queue.h"
#include "../Exception.h"

template <class T>
class linkQueue : public Queue<T>{
private:
    struct node{
        T data;
        node *next;
        node(const T &x, node *N = nullptr){
            data = x;
            next = N;
        }
        node(node *p = nullptr){
            next = p;
        }
        ~node(){}
    };

    node *front;
    node *rear;

public:
    linkQueue(){
        front = rear = nullptr;
    }
    ~linkQueue(){clear();};
    void clear() {
        node *p;
        while (front != nullptr){
            p = front;
            front = front->next;
            delete p;
        }
        rear = nullptr;
    }

    bool empty()const {
        return front == nullptr;
    }
    int size()const {
        node *p = front;
        int count = 0;
        while (p){
            count++;
            p = p->next;
        }
        return count;
    }

    void enQueue(const T &x) {
        if (rear == nullptr){
            //原队列为空
            front = rear = new node(x);
        } else{
            rear->next = new node(x);
            rear = rear->next;
        }
    }

    T deQueue() {
        if (empty()) throw outOfRange();
        node *p = front;
        T value = front->data;
        front = front->next;
        if (front == nullptr)//队列最后一个元素被取出，队尾为null
            rear = nullptr;
        delete p;
        return value;
    }

    T getHead()const {
        if (empty()) throw outOfRange();
        return front->data;
    }

};


#endif //DATAANDSTRUCT_LINKQUEUE_H
