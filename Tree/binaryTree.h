//
// Created by lyl on 2019/10/29.
//

#ifndef DATAANDSTRUCT_BINARYTREE_H
#define DATAANDSTRUCT_BINARYTREE_H

template <class T>
class binaryTree{
public:
    virtual void clear() = 0;
    virtual bool empty() const = 0;
    virtual int height() const = 0;
    virtual int size() const = 0;
    virtual void preOrderTraverse() const = 0;
    virtual void inOrderTraverse() const = 0;
    virtual void postOrderTraverse() const = 0;
    virtual void levelOrderTraverse() const = 0;
    virtual ~binaryTree(){};
};

#endif //DATAANDSTRUCT_BINARYTREE_H
