//
// Created by lyl on 2019/9/17.
//
#include "linkList.h"

using namespace std;
int main2() {
    linkList<int> linkList;
    linkList.getSimpleLinkList();
    linkList.traverse();
    linkList.inverse();
    linkList.traverse();
    cout<<"search 4"<<endl;
    cout<<linkList.search(4)<<endl;
    return 0;
}
