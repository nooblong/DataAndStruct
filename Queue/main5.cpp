//
// Created by lyl on 2019/10/15.
//
#include "seqQueue2.h"
#include <iostream>

using namespace std;

int main() {
    seqQueue<int> seqQueue(11);
    for (int i = 0; i < 10; ++i) {
        seqQueue.enQueue(i);
    }
    for (int j = 0; j < 8; ++j) {
        cout<<seqQueue.deQueue()<<" ";
    }
    for (int i = 0; i < 20; ++i) {
        seqQueue.enQueue(i);
    }
    for (int j = 0; j < 20; ++j) {
        cout<<seqQueue.deQueue()<<" ";
    }
}
