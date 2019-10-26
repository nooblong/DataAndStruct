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
    int i = 0;
    int j = 0;
    while (i < curLength && j < t.curLength) {
        if (data[i] == t[j]) {
            i++;
            j++;
        } else {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j >= t.curLength)
        return i - t.curLength;
    else
        return -1;
}

int String::kmpFind(const String &t, int *next) {
    int i = 0;
    int j = 0;
    int nextI = 0;
    while (i <= curLength){
        if (t.data[j] == data[i]){
            i++;
            j++;
        } else{
            int pos = next[j];
            j = pos;
            if (data[i] == t.data[j]){
                continue;
            } else{
                i++;
            }
        }
        if (j == t.curLength){
            return i-t.curLength;
        }
    }
    return -1;
}

void String::getNextVal(const String &t, int pos) {

}

int *String::getTmp() {
    int i = 1;
    int j = 0;
    int *tmp = new int[curLength];
    tmp[0] = 0;
    while (i <= curLength) {
        if (data[j] != data[i]) {
            if (i == curLength - 1) {
                while (j >= 0) {
                    if (j == 0) {
                        tmp[i] = 0;
                        return tmp;
                    }
                    j = tmp[j - 1];
                    if (data[j] == data[i]) {
                        tmp[i] = j + 1;
                        return tmp;
                    }
                }
            } else {
                while (j >= 0){
                    if (j == 0){
                        tmp[i] = 0;
                        break;
                    }
                    j = tmp[j-1];
                    if (data[j] == data[i]){
                        tmp[i] = j + 1;
                        break;
                    }
                }
                i++;
            }
        } else {
            tmp[i] = j + 1;
            i++;
            j++;
        }
    }
    return tmp;
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
    if (curLength != str.curLength)
        return false;
    return strcmp(data, str.data) == 0;
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
    else
        return data[n];
}

istream &operator>>(istream &istream1, String &str) {
    char *tmp = new char[10000];
    istream1 >> tmp;
    str.maxSize = 2 * strlen(tmp);
    str.data = new char[str.maxSize + 1];
    strcpy(str.data, tmp);
    str.curLength = strlen(tmp);
    delete[] tmp;
    return istream1;
}

ostream &operator<<(ostream &ostream1, String &str) {
    ostream1 << str.data;
    return ostream1;
}

void String::resize(int len) {
    maxSize = len;
    char *tmp = new char[maxSize + 1];
    strcpy(tmp, data);
    delete[]data;
    data = tmp;
}
