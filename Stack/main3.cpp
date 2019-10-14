//
// Created by lyl on 2019/10/8.
//
#include "SeqStack.h"
#include "dSeqStack.h"
#include "linkStack.h"
#include "calculator.h"
#include <iostream>
#include <cstring>

using namespace std;

void convert(int N) {
    linkStack<int> S;
    int e;
    while (0 != N) {
        S.push(N % 16);
        N = N / 16;
    }
    while (!S.empty()) {
        e = S.pop();
        if (e > 9)
            cout << char(e - 10 + 'A');
        else
            cout << e;
    }
}

bool match() {
    linkStack<char> T;
    char item;
    int i = 0;
    string expression;
    getline(cin, expression);
    while (i < expression.size()) {
        switch (expression[i]) {
            case '(':
                T.push(expression[i]);
                break;
            case ')':
                if (T.empty() || (item = T.getTop()) != '(') {
                    cout << "mismatched\n";
                    return false;
                } else {
                    T.pop();
                    break;
                }
            case '[':
                T.push(expression[i]);
            case ']':
                if (T.empty() || (item = T.getTop()) != '[') {
                    cout << "mismatched\n";
                    return false;
                } else {
                    T.pop();
                    break;
                }
            case '{':
                T.push(expression[i]);
                break;
            case '}':
                if (T.empty() || (item = T.getTop()) != '{') {
                    cout << "mismatched\n";
                    return false;
                } else {
                    T.pop();
                    break;
                }
        }
        i++;
    }
    if (T.empty()) {
        cout << "matched\n";
        return true;
    } else {
        cout<<"mismatched\n";
        return false;
    }
}

void testStack() {
    seqStack<int> ss(100);
    for (int i = 0; i < 10; ++i) {
        ss.push(i);
    }
    int size = ss.size();
    for (int j = 0; j < size; ++j) {
        cout << ss.pop() << " ";
    }
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
        cout << dss.pop(0) << " ";
    }
    cout << endl;
    for (int k = 0; k < num1; ++k) {
        cout << dss.pop(1) << " ";
    }
}

void testLinkStack() {
    linkStack<int> l;
    for (int i = 0; i < 10; ++i) {
        l.push(i);
    }
    for (int j = 0; j < 10; ++j) {
        cout << l.pop();
    }
}

int main() {
//    convert(1000);
//    match();
//    const char* a;
//    string str = "hello";
//    a = str.c_str();
//    char* b;
//    strcpy(b,a);
//    cout<<b;
//    calculator *c = new calculator((char*)"(2+2*2)*2=");
//    calculator *c = new calculator((char*)"2+2=");
//    c->printInfix();
//    cout<<c->calculateInfix()<<endl;
    calculator *d = new calculator((char*) "12+");
    d->infixToPostfix();
    d->printPostfix();
    delete(d);
}
