//
// Created by lyl on 2019/10/13.
//
#define __STDC_LIB_EXT1__

#include "../Exception.h"
#include "calculator.h"
#include <cstring>
#include <iostream>

using namespace std;

calculator::calculator(char *s) {
    size = strlen(s);
    infix = new char[size + 1];
    postfix = new char[2 * size];
    strcpy(infix, s);//copy s to infix
}

calculator::~calculator() {
    delete[]infix;
    delete[]postfix;
}

double calculator::spellNum(char *fix, int &i) {
    //传进来了i的地址
    //转换成double时，有几位数i就加几
    double num1 = 0, num2 = 0, num;
    int j = 0;
    while (fix[i] >= '0' && fix[i] <= '9')
        //小数点以前
        num1 = num1 * 10 + fix[i++] - '0';
    //小数点后
    if (fix[i] == '.') {
        i++;
        while (fix[i] >= '0' && fix[i] <= '9')
            num2 += (fix[i++] - '0') * 1.0 / pow(10.0, ++j);
    }
    return num1 + num2;
}

int calculator::priorInStack(char item) {
    int in;
    switch (item) {
        case '=':
            in = 0;
            break;
        case '(':
            in = 1;
            break;
        case '*':
        case '/':
            in = 5;
            break;
        case '+':
        case '-':
            in = 3;
            break;
        case ')':
            in = 6;
            break;
        default:
            throw badExpression();
    }
    return in;
}

int calculator::priorOutStack(char ch) {
    int out;
    switch (ch) {
        case '=':
            out = 0;
            break;
        case '(':
            out = 6;
            break;
        case '*':
        case '/':
            out = 4;
            break;
        case '+':
        case '-':
            out = 2;
            break;
        case ')':
            out = 1;
            break;
        default:
            throw badExpression();
    }
    return out;
}

int calculator::precede(char item, char ch) {
    if (priorInStack(item) < priorOutStack(ch))
        return -1;
    else if (priorInStack(item) == priorOutStack(ch))
        return 0;
    else
        return 1;
}

double calculator::operate(double a, char theta, double b) {
    double result;
    switch (theta) {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/': {
            if (fabs(b) <= 1e-6) throw divideByZero();
            else {
                result = a / b;
                break;
            }
        }
    }
    return result;
}

double calculator::calculateInfix() {
    oper_ator.clear();
    oper_and.clear();
    int i = 0;
    char item, theta;
    double num, a, b;
    oper_ator.push('=');
    while (!oper_ator.empty()) {
        if ((infix[i] >= '0' && infix[i] <= '9') || infix[i] == '.') {
            //如果是数字，push进操作数
            num = spellNum(infix, i);
            oper_and.push(num);
        } else {
            //如果不是数字,比较优先级
            item = oper_ator.getTop();
            switch (precede(item, infix[i])) {
                case -1:
                    //栈内>栈外
                    oper_ator.push(infix[i]);
                    i++;
                    break;
                case 0:
                    //栈内=栈外
                    item = oper_ator.pop();
                    //item进行下一个while循环
                    if (item != '=')
                        i++;//删除括号或者=
                    break;
                case 1:
                    //栈内<栈外
                    theta = oper_ator.pop();
                    b = oper_and.pop();
                    a = oper_and.pop();
                    oper_and.push(operate(a, theta, b));
            }
        }
    }
    num = oper_and.pop();
    if (!oper_and.empty()) throw badExpression();
    return num;
}

double calculator::calculatePostfix() {
    int i = 0;
    oper_and.clear();
    while (postfix[i] != '\0'){
        if ((infix[i] >= '0' && infix[i] <= '9') || infix[i] == '.'){
            oper_and.push(spellNum(postfix,i));
        } else if (postfix[i] == ' ')
            i++;
        else{
            double a, b, num;
            b = oper_and.pop();
            a = oper_and.pop();
            num = operate(a, infix[i], b);
            oper_and.push(num);
            i++;
        }
    }
    double result = oper_and.pop();
    if (!oper_and.empty())
        throw badExpression();
    return result;
}

void calculator::infixToPostfix() {
    int i = 0, j = 0;
    double num;
    char item;
    oper_ator.push('=');
    while (!oper_ator.empty()) {
        if ((infix[i] >= '0' && infix[i] <= '9') || infix[i] == '.') {
//            num = spellNum(infix,i);
            postfix[j] = infix[i];
            j++;
            i++;
        } else {
            postfix[j] = ' ';//空格用于区分后缀表达式中各组成部分
            j++;
            item = oper_ator.getTop();
            switch (precede(item, infix[i])) {//infix级别高，入栈
                case -1:
                    //栈外优先级比栈内低
                    oper_ator.push(infix[i]);
                    i++;
                    break;
                case 1:
                    //item级别高，出栈
                    item = oper_ator.pop();
                    postfix[j++] = item;
                    break;
                case 0:
                    //删除括号或=
                    item = oper_ator.pop();
                    if (item != '=')
                        i++;
                    break;
            }
        }
    }
    postfix[j] = '\0';
}

void calculator::printInfix() {
    int i = 0;
    while (infix[i] != '\0') {
        cout << infix[i++];
    }
    cout << endl;
}

void calculator::printPostfix() {
    int i = 0;
    while (postfix[i] != '\0') {
        cout << postfix[i++];
    }
    cout << endl;
}
