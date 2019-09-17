//
// Created by lyl on 2019/9/16.
//
#include "SeqLIst.h"
#include<iostream>

using namespace std;
class A {
public:
    int main1() {
        SeqLIst<int> list(2);
        for (int i = 0; i < 10; ++i) {
            list.insert(i, i * 2);
        }
        list.traverse();
        cout << "size, maxSize: " << list.size() << "  " << list.maxSize << endl;
        cout << "search 10:  " << list.search(10) << endl;
        cout << "remove 10:  " << endl;
        list.remove(list.search(10));
        list.traverse();
        cout << "inverse" << endl;
        list.inverse();
        list.traverse();

        cout << "list2-----------------------\n";
        SeqLIst<int> listB(100);
        listB.insert(0, 9);
        listB.insert(1, 99);
        listB.traverse();
        cout << "-------------------------\n";
        cout << "after listB.Union(list)\nlistB:\n" << endl;
        listB.Union(list);
        listB.traverse();
        cout << "list:" << endl;
        list.traverse();
        cout << "-------------------------\nafter list.Union(listB)\nlist:\n";
        list.Union(listB);
        list.traverse();
        return 0;
    }
};