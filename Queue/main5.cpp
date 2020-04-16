//
// Created by lyl on 2019/10/15.
//
#include "seqQueue2.h"
#include <iostream>

using namespace std;

int main5() {
    seqQueue<int> seqQueue(5);
    cout<<"add 0-19\n";
    for (int i = 0; i < 20; ++i) {
        seqQueue.enQueue(i);
    }
    cout<<"de 10\n";
    for (int j = 0; j < 8; ++j) {
        cout<<seqQueue.deQueue()<<" ";
    }
    cout<<"add 0-7\n";
    for (int i = 0; i < 8; ++i) {
        seqQueue.enQueue(i);
    }
    cout<<"de 10\n";
    for (int j = 0; j < 10; ++j) {
        cout<<seqQueue.deQueue()<<" ";
    }
    cout<<"de 20\n";
    for (int k = 0; k < 10; ++k) {
        cout<<seqQueue.deQueue()<<" ";
    }
    cout<<"add 0-99\n";
    for (int i = 0; i < 100; ++i) {
        seqQueue.enQueue(i);
    }
    cout<<"de 100\n";
    for (int j = 0; j < 100; ++j) {
        cout<<seqQueue.deQueue()<<" ";
    }
    return 0;
}
