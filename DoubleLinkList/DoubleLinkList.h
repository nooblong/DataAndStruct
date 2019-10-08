//
// Created by lyl on 2019/9/27.
//

#ifndef DATAANDSTRUCT_DOUBLELINKLIST_H
#define DATAANDSTRUCT_DOUBLELINKLIST_H

#include <iostream>
#include "../List.h"

using namespace std;

template<class T>
class DoubleLinkList : public List<T> {
private:
    struct Node {
        T data;
        Node *prior;
        Node *next;

        Node(const T &data, Node *prior = nullptr, Node *next = nullptr) {
            this->data = data;
            this->prior = prior;
            this->next = next;
        }

        Node() : next(nullptr), prior(nullptr) {}

        ~Node() {}
    };
    T data;
    Node *prior, *next;

public:
    DoubleLinkList();
};

template <class T>
DoubleLinkList<T>::DoubleLinkList() {

}


#endif //DATAANDSTRUCT_DOUBLELINKLIST_H
