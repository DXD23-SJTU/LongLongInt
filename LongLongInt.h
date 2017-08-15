//
// Created by 徐达丁 on 2017/8/15.
//

#ifndef C_LONGLONGINT_H
#define C_LONGLONGINT_H

#include <cstdlib>
#include <iostream>
#include <stack>
using namespace std;

class LongLongInt {
private:
    struct node {
        int data{};
        node *next;

        node(const int x, node *N = NULL) {
            {
                data = x;
                next = N;
            }
        }

        node() : next(NULL) {}

        ~node() {}
    };

    node *head;
public:
    LongLongInt(const char *str);

    LongLongInt();

    void Lprint();

    LongLongInt operator+(const LongLongInt &a);
    LongLongInt& operator=(const LongLongInt &a);

    ~LongLongInt();

};

#endif //C_LONGLONGINT_H
