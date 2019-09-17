//
// Created by lyl on 2019/9/17.
//

#include "linkList.h"
#include <iostream>

using namespace std;

template<class elemType>
linkList<elemType>::linkList() {
    head = tail = new Node();
    curLength = 0;
}

template<class elemType>
linkList<elemType>::~linkList() {
    clear();
    delete head;
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
    if (i < -1 || i > curLength -1){
        return nullptr;
    }
    Node *p = head;
    int count = 0;
    while (count <= i){
        p = p->next;
        count++;
    }
    return p;
}

template<class elemType>
int linkList<elemType>::prior(const elemType &value) const {

}
