//
// Created by lyl on 2019/10/11.
//

#ifndef DATAANDSTRUCT_LINKSTACK_H
#define DATAANDSTRUCT_LINKSTACK_H

#include <iostream>
#include "Stack.h"
#include "../Exception.h"

using namespace std;

template <class T> class linkStack : public Stack<T>{
private:
    struct Node{
        T data;
        Node* next;
        Node(){
            next = nullptr;
        }
        Node(const T &value, Node *p = nullptr){
            data = value;
            next = p;
        }
    };
    Node *top;
public:
    linkStack(){top = nullptr;}
    ~linkStack(){clear();}
    void clear();
    bool empty()const { return top == nullptr;}
    int size()const ;
    void push(const T &value);
    T pop();
    T getTop()const;
    void traverse();
};

template<class T>
void linkStack<T>::clear() {
    Node* p;
    while (top != nullptr){
        p = top;
        top = top->next;
        delete p;
    }
}

template<class T>
int linkStack<T>::size() const {
    Node *p = top;
    int count = 0;
    while (p){
        count++;
        p = p->next;
    }
    return count;
}

template<class T>
void linkStack<T>::push(const T &value) {
    Node *p = new Node(value,top);
    top = p;
}

template<class T>
T linkStack<T>::pop() {
    if(empty())
        throw outOfRange();
    Node *p = top;
    T value = p->data;
    top = top->next;
    delete p;
    return value;
}

template<class T>
T linkStack<T>::getTop() const {
    if (empty())
        throw outOfRange();
    return top->data;
}

template<class T>
void linkStack<T>::traverse() {
    Node *p = top->next;
    while (p->next){
        cout<<p->data<<" ";
    }
    cout<<endl;
}


#endif //DATAANDSTRUCT_LINKSTACK_H
