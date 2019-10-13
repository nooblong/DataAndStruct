//
// Created by lyl on 2019/10/13.
//

#ifndef DATAANDSTRUCT_CALCULATOR_H
#define DATAANDSTRUCT_CALCULATOR_H


#include "linkStack.h"
#include <cstring>
class calculator {
private:
    linkStack<char> oper_ator;//运算符
    linkStack<double> oper_and;//操作数
    char* infix;//中缀表达式
    char* postfix;//后缀表达式
    int size;
public:
    calculator(char *s);
    ~calculator();
    double spellNum(char *fix, int &i);//change string to double
    int priorInStack(char item);//cal prior inside stack
    int priorOutStack(char ch);//cal prior outside stack
    int precede(char item, char ch);//cal prior beside inStack and outStack
    double operate(double a, char theta, double b);//theta a and b
    double calculateInfix();
    double calculatePostfix();
    void infixToPostfix();
    void printInfix();
    void printPostfix();
};


#endif //DATAANDSTRUCT_CALCULATOR_H
