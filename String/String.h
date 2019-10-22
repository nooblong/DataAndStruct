//
// Created by lyl on 2019/10/22.
//

#ifndef DATAANDSTRUCT_STRING_H
#define DATAANDSTRUCT_STRING_H


#include <iostream>
#include "../Exception.h"
using namespace std;
class String {
public:
    String(const char *str = nullptr);

    String(const String &str);

    ~String() { delete[]data; }

    int capacity() const { return maxSize; }

    int size() const { return curLength; }

    bool empty() const { return curLength == 0; }

    int compare(const String &s) const;

    String subStr(int pos, int num) const;

    int bfFind(const String &t, int pos = 0) const ;

    String &insert(int pos, const String &s);

    String &erase(int pos, int num);

    const char* toCharStr() const { return data;}

    int kmpFind(const String &t, int *next);

    void getNextVal(const String &t, int pos = 0);

    bool operator==(const String &str);

    String&operator+(const String &str);

    String&operator=(const String &str);

    char &operator[](int n)const ;

    friend istream&operator>>(istream &cin, String &str);

    friend ostream&operator<<(ostream &cout, String &str);

private:
    char *data;
    int maxSize;
    int curLength;
    void resize(int len);
};


#endif //DATAANDSTRUCT_STRING_H
