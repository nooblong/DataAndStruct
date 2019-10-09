//
// Created by lyl on 2019/10/8.
//
#include "SeqStack.h"
#include <iostream>
using namespace std;

int main(){
    seqStack<int> ss(100);
    for (int i = 0; i < 10; ++i) {
        ss.push(i);
    }
    int size = ss.size();
    for (int j = 0; j < size; ++j) {
        cout<<ss.pop() << " ";
    }
}