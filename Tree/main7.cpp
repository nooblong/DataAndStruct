//
// Created by lyl on 2019/10/29.
//
#include "BinaryLinkList.h"
#include <iostream>
using namespace std;
int main(){
    cout<<"main7"<<endl;
    auto *b = new BinaryLinkList<int>();
    b->levelOrderCreate(0);
    b->preOrderTraverse();
    return 0;
}
