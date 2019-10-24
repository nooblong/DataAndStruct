//
// Created by lyl on 2019/10/22.
//

#include <cstring>
#include "String.h"

String::String(const char *str) {
    maxSize = 2 * strlen(str);
    data = new char[maxSize + 1];
    strcpy(data, str);
    curLength = strlen(data);
}

int String::bfFind(const String &t, int pos) const {
    return 0;
}

int String::kmpFind(const String &t, int *next) {
    return 0;
}

void String::getNextVal(const String &t, int pos) {

}

String::String(const String &str) {
    maxSize = str.maxSize;
    data = new char[maxSize + 1];
    strcpy(data, str.toCharStr());
    curLength = str.curLength;
}

int String::compare(const String &s) const {
    int i = 0;
    while (s.data[i] != '\0' || this->data[i] != '\0') {
        if (this->data[i] > s.data[i])
            return 1;
        else if (this->data[i] < s.data[i])
            return -1;
        i++;
    }
}

String String::subStr(int pos, int num) const {
    int i;
    String tmp("");
    if (pos > curLength || pos < 0)
        throw outOfRange();
    if (num < 0)
        throw badSize();
    if (num > curLength - pos)
        num = curLength - pos;
    delete[]tmp.data;
    tmp.maxSize = tmp.curLength = num;
    tmp.data = new char[num + 1];
    for (i = 0; i < num; ++i) {
        tmp.data[i] = data[pos + i];
        tmp.data[i] = '\0';
    }
    return tmp;
}

String &String::insert(int pos, const String &s) {
    if (pos > curLength || pos < 0)
        throw outOfRange();
    if (curLength + s.curLength > maxSize)
        resize(2 * (curLength + s.curLength));
    for (int i = 0; i < curLength; ++i) {
        data[i + s.curLength] = data[i];
    }
    for (int j = 0; j < s.curLength; ++j) {
        data[pos + j] = s.data[j];
    }
    curLength += s.curLength;
    return *this;
}

String &String::erase(int pos, int num) {
    if (pos < 0 || pos > curLength - 1)
        throw outOfRange();
    if (num < 0)
        throw badSize();
    if (num > curLength - pos) {
        num = curLength - pos;
    }
    for (int j = pos + num; j <= curLength; ++j) {
        data[j - num] = data[j];
    }
    curLength -= num;
    return *this;
}

bool String::operator==(const String &str) {
    return false;
}

String &String::operator+(const String &str) {
    if (maxSize < curLength + str.size())
        resize(2 * (curLength + str.size()));
    strcat(data, str.data);
    curLength += str.curLength;
    return *this;
}

String &String::operator=(const String &str) {
    if (this == &str)
        return *this;
    delete[] data;
    maxSize = str.maxSize;
    data = new char[maxSize + 1];
    strcpy(data, str.toCharStr());
    curLength = str.curLength;
    return *this;
}

char &String::operator[](int n) const {
    if (n < 0 || n >= curLength)
        throw outOfRange();
}

istream &operator>>(istream &cin, String &str) {
    char *tmp = new char[10000];
    cin >> tmp;
    str.maxSize = 2 * strlen(tmp);
    str.data = new char[str.maxSize + 1];
    strcpy(str.data, tmp);
    str.curLength = strlen(tmp);
    delete[] tmp;
    return cin;
}

ostream &operator<<(ostream &cout, String &str) {
    cout << str.data;
    return cout;
}

void String::resize(int len) {
    maxSize = len;
    char *tmp = new char[maxSize + 1];
    strcpy(tmp, data);
    delete[]data;
    data = tmp;
}
