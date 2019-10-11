//
// Created by lyl on 2019/10/8.
//
#include "SeqStack.h"
#include "dSeqStack.h"
#include <iostream>

using namespace std;

int main() {
//    seqStack<int> ss(100);
//    for (int i = 0; i < 10; ++i) {
//        ss.push(i);
//    }
//    int size = ss.size();
//    for (int j = 0; j < size; ++j) {
//        cout << ss.pop() << " ";
//    }
    cout << endl;

    dSeqStack<int> dss(5);
    for (int i = 0; i < 20; ++i) {
        dss.push(i, 0);
        cout << i << " ";
    }
    cout << endl;
    for (int i = 10; i > 0; --i) {
        dss.push(i, 1);
        cout << i << " ";
    }
    cout << endl;
    int num0 = dss.size(0);
    int num1 = dss.size(1);
    for (int j = 0; j < num0; j++) {
        cout<<dss.pop(0)<<" ";
    }
    cout << endl;
    for (int k = 0; k < num1; ++k) {
        cout<<dss.pop(1)<<" ";
    }
}