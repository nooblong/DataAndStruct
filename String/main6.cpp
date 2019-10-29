//
// Created by lyl on 2019/10/24.
//

#include "string.h"
#include <iostream>
using namespace std;

int main6(){
    String s("abcdabca");
    cout<<s<<endl;
    int* tmp = nullptr;
    tmp = s.getTmp();
    for (int i = 0; i < s.size(); ++i) {
        cout<<tmp[i]<<" ";
    }
    cout<<endl;

    String s1("aabaabaaaqaqaababaaqaqbbb");
    int *tmp1 = s1.getTmp();
    for (int j = 0; j < s1.size(); ++j) {
        cout<<tmp1[j]<<" ";
    }
    cout<<endl;

    cout<<s1.kmpFind("qaqbbb", tmp1)<<endl;
}
