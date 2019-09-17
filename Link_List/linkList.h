//
// Created by lyl on 2019/9/17.
//

#ifndef DATAANDSTRUCT_LINKLIST_H
#define DATAANDSTRUCT_LINKLIST_H

#include "../Linear_List/List.h"

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
    Node *tail;
    int curLength;
    Node *getPosition(int i)const ;

public:
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




#endif //DATAANDSTRUCT_LINKLIST_H
