//
// Created by lyl on 2019/10/29.
//

#ifndef DATAANDSTRUCT_BINARYLINKLIST_H
#define DATAANDSTRUCT_BINARYLINKLIST_H

#include "binaryTree.h"
#include <iostream>
#include <stack>
using namespace std;

template<class T>
class BinaryLinkList : public binaryTree<T> {
private:
    struct Node {
        Node *left, *right;
        T data;

        Node() : left(nullptr), right(nullptr) {
            left = nullptr;
        }

        Node(T value, Node *l = nullptr, Node *r = nullptr) {
            data = value;
            left = l;
            right = r;
        }

        ~Node() {}
    };

    Node *root;

    void clear(Node *t);

    int size(Node *t);

    int height(Node *t);

    int leafNum(Node *t);

    void preOrder(Node *t) const;

    void inOrder(Node *t) const;

    void postOrder(Node *t) const;

    void postOrderCreat(Node *t) const;

public:
    BinaryLinkList() : root(nullptr) {}//构造空二叉树
    ~BinaryLinkList() { clear(); }

    bool empty() const { return root == nullptr; }

    void clear() {
        if (root) clear(root);
        root = nullptr;
    }

    int size() const { return size(root); }

    int height() const { return height(root); }

    int leafNum() const { return leafNum(root); }

    void preOrderTraverse() const { if (root) preOrder(root); }

    void inOrderTraverse() const { if (root) inOrder(root); }

    void postOrderTraverse() const { if (root) postOrder(root); }

    void levelOrderTraverse();

    void preOrderWithStack() const;

    void inOrderWithStack() const;

    void postOrderWithStack() const;

    void levelOrderCreate(T flag);//利用外部节点的层次序列创建二叉树

    void preOrderCreate(T flag) {
        preOrderCreate(flag, root);
    }
};

template<class T>
void BinaryLinkList<T>::clear(BinaryLinkList::Node *t) {

}

template<class T>
int BinaryLinkList<T>::size(BinaryLinkList::Node *t) {
    return 0;
}

template<class T>
int BinaryLinkList<T>::height(BinaryLinkList::Node *t) {
    return 0;
}

template<class T>
int BinaryLinkList<T>::leafNum(BinaryLinkList::Node *t) {
    return 0;
}

template<class T>
void BinaryLinkList<T>::preOrder(BinaryLinkList::Node *t) const {
    if (t){
        cout<<t->data<<" ";
        preOrder(t->left);
        preOrder(t->right);
    }
}

template<class T>
void BinaryLinkList<T>::inOrder(BinaryLinkList::Node *t) const {
    if (t){
        inOrder(t->left);
        cout<<t->data<<" ";
        inOrder(t->right);
    }
}

template<class T>
void BinaryLinkList<T>::postOrder(BinaryLinkList::Node *t) const {
    if (t){
        postOrder(t->left);
        postOrder(t->right);
        cout<<t->data<<" ";
    }
}

template<class T>
void BinaryLinkList<T>::postOrderCreat(BinaryLinkList::Node *t) const {

}

template<class T>
void BinaryLinkList<T>::levelOrderTraverse() {

}

template<class T>
void BinaryLinkList<T>::preOrderWithStack() const {
    stack<Node*> s;
    Node *p = root;
    while (!s.empty() || p){
        if (p){
            cout<<p->data<<" ";
            s.push(p);
            p = p->left;
        } else {
            p = s.top();
            s.pop();
            p = p->right;
        }
    }
}

template<class T>
void BinaryLinkList<T>::inOrderWithStack() const {

}

template<class T>
void BinaryLinkList<T>::postOrderWithStack() const {

}

template<class T>
void BinaryLinkList<T>::levelOrderCreate(T flag) {

}

#endif //DATAANDSTRUCT_BINARYLINKLIST_H
