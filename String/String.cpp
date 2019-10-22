//
// Created by lyl on 2019/10/22.
//

#include <cstring>
#include "String.h"
String::String(const char *str) {
    maxSize = 2*strlen(str);
    data = new char[maxSize + 1];
    strcpy(data, str);
    curLength = strlen(data);
}

String::String(const String &str) {
    maxSize = str.maxSize;
    data = new char[maxSize+1];
    strcpy(data,str.toCharStr());
    curLength = str.curLength;
}

int String::compare(const String &s) const {
    int i = 0;
    while (s.data[i] != '\0' || this->data[i] != '\0'){
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
    delete []tmp.data;
    tmp.maxSize = tmp.curLength = num;
    tmp.data = new char[num+1];
}

int String::bfFind(const String &t, int pos) const {
    return 0;
}

String &String::insert(int pos, const String &s) {
    return <#initializer#>;
}

String &String::erase(int pos, int num) {
    return <#initializer#>;
}

int String::kmpFind(const String &t, int *next) {
    return 0;
}

void String::getNextVal(const String &t, int pos) {

}

bool String::operator==(const String &str) {
    return false;
}

String &String::operator+(const String &str) {
    return <#initializer#>;
}

String &String::operator=(const String &str) {
    return <#initializer#>;
}

char &String::operator[](int n) const {
    return <#initializer#>;
}

istream &operator>>(istream &cin, String &str) {
    return <#initializer#>;
}

ostream &operator<<(ostream &cout, String &str) {
    return <#initializer#>;
}

void String::resize(int len) {

}
