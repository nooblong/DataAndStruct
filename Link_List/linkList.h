//
// Created by lyl on 2019/9/17.
//

#ifndef DATAANDSTRUCT_LINKLIST_H
#define DATAANDSTRUCT_LINKLIST_H

#include "../List.h"
#include "../Exception.h"
#include <iostream>
using namespace std;

template <class elemType>
class linkList : public List<elemType> {
private:
    struct Node{
        elemType data;
        Node *next;
        Node(const elemType value, Node *p = nullptr){
            data = value;
            next = p;
        }
        Node(Node *p = nullptr){
            next = p;
        }
    };

    Node *head;
    int curLength;
    Node *tail;
    Node *getPosition(int i)const ;
public:
    void getSimpleLinkList();
    linkList();
    ~linkList();
    void clear();
    bool empty()const { return head->next == nullptr;}
    int size()const{ return curLength;}
    void insert(int i, const elemType &value);
    void remove(int i);
    int search(const elemType&value)const;
    int prior(const elemType &value)const ;
    elemType visit(int i)const ;
    void traverse()const ;
    void headCreate();
    void tailCreate();
    void inverse();
};

template<class elemType>
linkList<elemType>::~linkList() {
    clear();
    delete head;
}

template<class elemType>
linkList<elemType>::linkList() {
    head = tail = new Node();
    curLength = 0;
}

template<class elemType>
void linkList<elemType>::clear() {
    Node *p, *tmp;
    p = head->next;
    while (p != nullptr) {
        tmp = p;
        p = p->next;
        delete tmp;
    }
    head->next = nullptr;
    tail = head;
    curLength = 0;
}

template<class elemType>
void linkList<elemType>::traverse() const {
    Node *p = head->next;
    cout << "traverse: " << endl;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

template<class elemType>
typename linkList<elemType>::Node *linkList<elemType>::getPosition(int i) const {
    if (i < -1 || i > curLength - 1) {
        return nullptr;
    }
    Node *p = head;
    int count = 0;
    while (count <= i) {
        p = p->next;
        count++;
    }
    return p;
}

template<class elemType>
int linkList<elemType>::prior(const elemType &value) const {
    Node *p = head->next;
    Node *pre = NULL;
    int count = -1;
    while (p && p->data != value) {
        pre = p;
        p = p->next;
        count++;
    }
    if (p == NULL)
        return -1;
    else
        return count;
}

template<class elemType>
void linkList<elemType>::insert(int i, const elemType &value) {
    //O(n)
    Node *p, *q;
    if (i < 0 || i > curLength)
        throw outOfRange();
    p = getPosition(i - 1);//p是第八位的前驱
    q = new Node(value, p->next);
    p->next = q;
    if (p == tail)
        tail = q;
    curLength++;
}

template<class elemType>
void linkList<elemType>::remove(int i) {
    Node *pre, *p;
    if (i < 0 || i > curLength - 1)
        throw outOfRange();
    pre = getPosition(i);
    p = pre->next;
    if (p == tail) {
        tail = pre;
        pre->next = NULL;
        delete p;
    } else {
        pre->next = p->next;
        delete p;
    }
    curLength--;
}

template <class elemType>
void linkList<elemType>::getSimpleLinkList(){
    Node *p;
    elemType value, flag;
    for (int i = 0; i < 10; i++) {
        p = new Node(i, nullptr);
        tail->next = p;
        tail = p;
        curLength++;
    }
}

template<class elemType>
void linkList<elemType>::headCreate() {
    Node *p;
    elemType value, flag;
    cout << "input elements, ended with: ";
    cin >> flag;
    cout<<"value: ";
    while (cin>>value && value != flag){
        cout<<"value: ";
//        p->data = value;
//        p->next = head->next;
        p = new Node(value, head->next);
        head->next = p;
        if (head == tail)
            tail = p;
        curLength++;
    }
}

template <class elemType>
void linkList<elemType>::tailCreate() {
    Node *p;
    elemType value, flag;
    cout << "input elements, ended with: ";
    cin >> flag;
    cout<<"value: ";
    while (cin>>value && value != flag){
        cout<<"value: ";
        p = new Node(value, nullptr);
        tail->next = p;
        tail = p;
        curLength++;
    }
}

template <class elemType>
void linkList<elemType>::inverse() {
    Node *p, *tmp;
    p = head->next;
    head->next = NULL;
    if (p)
        tail = p;
    while (p){
        tmp = p->next;
        p->next = head->next;
        head->next = p;
        p = tmp;
    }
}

template<class elemType>
int linkList<elemType>::search(const elemType &value) const {
    Node *p = head->next;
    int count = 0;
    while (p != NULL && p->data != value){
        p = p->next;
        count++;
    }
    if (p == NULL)
        return -1;
    else
        return count;
}

template<class elemType>
elemType linkList<elemType>::visit(int i) const {
    return 1;
}


#endif //DATAANDSTRUCT_LINKLIST_H
