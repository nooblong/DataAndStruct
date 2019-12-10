//
// Created by lyl on 2019/10/29.
//

#ifndef DATAANDSTRUCT_BINARYLINKLIST_H
#define DATAANDSTRUCT_BINARYLINKLIST_H

#include <queue>
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

    void levelOrderTraverse() const;

    void preOrderWithStack() const;

    void inOrderWithStack() const;

    void postOrderWithStack() const;

    void levelOrderCreate(T flag);//利用外部节点的层次序列创建二叉树

    void preOrderCreate(T flag, Node *& t) {
        T value;
        cin >> value;
        if (value != flag){
            t = new Node(value);
            preOrderCreate(flag, t->left);
            preOrderCreate(flag, t->right);
        }
    }
};

template<class T>
void BinaryLinkList<T>::clear(BinaryLinkList::Node *t) {
    if (t->left)
        clear(t->left);
    if (t->right)
        clear(t->right);
    delete t;
}

template<class T>
int BinaryLinkList<T>::size(BinaryLinkList::Node *t) {
    if (t == nullptr)
        return 0;
    return 1 + size(t->left) + size(t->right);
}

template<class T>
int BinaryLinkList<T>::height(BinaryLinkList::Node *t) {
    if (t == nullptr)
        return 0;
    else{
        int lh = height(t->left), rh = height(t->right);
        return 1 + ((lh > rh) ? lh : rh);
    }
}

template<class T>
int BinaryLinkList<T>::leafNum(BinaryLinkList::Node *t) {
    if (t == nullptr)
        return 0;
    else if ((t->left == nullptr) && (t->right == nullptr))
        return 1;
    else
        return leafNum(t->left) + leafNum(t->right);
}

template<class T>
void BinaryLinkList<T>::preOrder(BinaryLinkList::Node *t) const {
    if (t) {
        cout << t->data << " ";
        preOrder(t->left);
        preOrder(t->right);
    }
}

template<class T>
void BinaryLinkList<T>::inOrder(BinaryLinkList::Node *t) const {
    if (t) {
        inOrder(t->left);
        cout << t->data << " ";
        inOrder(t->right);
    }
}

template<class T>
void BinaryLinkList<T>::postOrder(BinaryLinkList::Node *t) const {
    if (t) {
        postOrder(t->left);
        postOrder(t->right);
        cout << t->data << " ";
    }
}

template<class T>
void BinaryLinkList<T>::postOrderCreat(BinaryLinkList::Node *t) const {

}

template<class T>
void BinaryLinkList<T>::levelOrderTraverse() const {

}

template<class T>
void BinaryLinkList<T>::preOrderWithStack() const {
    stack<Node *> s;
    Node *p = root;
    while (!s.empty() || p) {
        if (p) {
            cout << p->data << " ";
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
    stack<Node*> s;
    Node *p = root;
    while (!s.empty() || p){
        if (p){
            s.push(p);
            p = p->left;
        } else{
            p = s.top();
            s.pop();
            cout<< p->data << ' ';
            p = p->right;
        }
    }
}

template<class T>
void BinaryLinkList<T>::postOrderWithStack() const {
    enum ChileType{Left, Right};
    struct StackElem{
        Node* pointer;
        ChileType flag;
    };
    StackElem elem;
    stack<StackElem> S;
    Node *p = root;
    while (!S.empty() || p){
        while (p != nullptr){
            elem.pointer = p;
            elem.flag = Left;
            S.push(elem);
            p = p->left;
        }
        elem = S.top();
        S.pop();
        p = elem.pointer;
        if (elem.flag == Left){
            elem.flag = Right;
            S.push(elem);
            p = p->right;
        } else{
            cout<< p->data << ' ';
            p = nullptr;
        }
    }
}

template<class T>
void BinaryLinkList<T>::levelOrderCreate(T flag) {
    queue<Node*> que;
    Node *p = root;
    if (p){
        que.push(p);
    }
    while (!que.empty()){
        p = que.front();
        que.pop();
        cout << p->data << ' ';
        if (p->left != nullptr)
            que.push(p->left);
        if  (p->right != nullptr)
            que.push(p->right);
    }
}

#endif //DATAANDSTRUCT_BINARYLINKLIST_H
