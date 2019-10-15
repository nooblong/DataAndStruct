//
// Created by lyl on 2019/10/15.
//
#include "seqQueue1.h"
#include <iostream>

using namespace std;

int main() {
    seqQueue<int> seqQueue(100);
    for (int i = 0; i < 10; ++i) {
        seqQueue.enQueue(i);
    }
    for (int j = 0; j < 10; ++j) {
        cout<<seqQueue.deQueue()<<" ";
    }
    seqQueue.resize();
    cout<<endl;
    for (int i = 0; i < 30; ++i) {
        seqQueue.enQueue(i);
    }
    for (int j = 0; j < 30; ++j) {
        cout<<seqQueue.deQueue()<<" ";
    }
}
