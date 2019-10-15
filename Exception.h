//
// Created by lyl on 2019/9/11.
//
#ifndef DATAANDSTRUCT_EXCEPTION_H
#define DATAANDSTRUCT_EXCEPTION_H
#include <exception>
#include <math.h>
using namespace std;
class outOfRange : public exception {
public:
    const char *what() const throw() {
        return "Error,Out of Range\n";
    }
};

class badSize : public exception {
public:
    const char *what() const throw() {
        return "Error,Bad Size";
    }
};

class divideByZero:public exception{
public:
    const char *waht() const throw(){
        return "Error, Divide by zero";
    }
};

class badExpression:public exception{
public:
    const char *waht() const throw(){
        return "Error, bad expression";
    }
};

#endif