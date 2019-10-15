//
// Created by lyl on 2019/10/15.
//
#include "seqQueue.h"
#include <iostream>
using namespace std;

int main(){
    seqQueue<int> seqQueue(5);
    for (int i = 0; i < 4; ++i) {
        int num = i;
        seqQueue.enQueue(num);
    }
    for (int j = 0; j < 3; ++j) {
        cout<<seqQueue.deQueue();
    }
    seqQueue.enQueue(9);
    seqQueue.enQueue(99);
    seqQueue.enQueue(999);
    cout<<endl;
    cout<<seqQueue.deQueue();
    cout<<seqQueue.deQueue();
    cout<<seqQueue.deQueue();
    cout<<seqQueue.deQueue();
    seqQueue.enQueue(1);
    seqQueue.enQueue(1);
    seqQueue.enQueue(1);
    seqQueue.enQueue(1);
    seqQueue.enQueue(1);
    seqQueue.enQueue(1);
    cout<<endl;
    cout<<seqQueue.maxSIze;
//    for (int j = 0; j < 6; ++j) {
//        cout<<seqQueue.deQueue()<< " ";
//    }
    cout<<endl;
}
