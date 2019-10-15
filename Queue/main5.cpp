//
// Created by lyl on 2019/10/15.
//
#include "seqQueue.h"
#include <iostream>
using namespace std;

int main(){
    seqQueue<int> seqQueue(5);
    for (int i = 0; i < 30; i++) {
        seqQueue.enQueue(i);
        seqQueue.traverse();
    }

    cout<<seqQueue.maxSIze;
    cout<<endl;
            for (int j = 0; j < 20; ++j) {
            cout<<seqQueue.deQueue()<< " ";
        }
        cout<<endl;
}
