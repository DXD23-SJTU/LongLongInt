//
// Created by 徐达丁 on 2017/8/15.
//
#include <list>
#include "LongLongInt.h"

LongLongInt::LongLongInt(const char *str) {
    head = new node;
    while (*str != 0) {
        node *p = new node;
        int num;
        num = (int) *str - '0';
        p->data = num;
        p->next = head->next;
        head->next = p;
        str++;
    }
}

LongLongInt::LongLongInt() {
    head = new node;
}

LongLongInt::~LongLongInt() {
    node *p = head->next;
    while (p != NULL) {
        node *tmp = p;
        p = p->next;
        delete tmp;
    }
}

void LongLongInt::Lprint() {
    stack <int,list<int>> s1;
    node *p;
    p = head->next;
    while (p != NULL) {
        s1.push(p->data);
        p = p->next;
    }
    while(!s1.empty()){
        cout<<s1.top();
        s1.pop();
    }
}

LongLongInt LongLongInt::operator+(const LongLongInt &a) {
    int flag = 0;
    LongLongInt result;
    node *p1 = head->next;
    node *p2 = a.head->next;
    while (p1 != NULL || p2 != NULL) {
        int sum = 0;
        if (p1 == NULL) {
            sum = p2->data;
            sum = sum + flag;
            flag = 0;
            p2 = p2->next;
        } else if (p2 == NULL) {
            sum = p1->data;
            sum = sum + flag;
            flag = 0;
            p1 = p1->next;
        } else {
            sum = (p1->data + p2->data) % 10;
            sum = sum + flag;
            flag = 0;
            if ((p1->data + p2->data) >= 10) flag = 1;
            p1 = p1->next;
            p2 = p2->next;
        }
        node *p = new node;
        p->data = sum;
        p->next = result.head->next;
        result.head->next = p;
    }

    return result;
}

LongLongInt &LongLongInt::operator=(const LongLongInt &a) {
    node *p = a.head->next;
    while (p != NULL) {
        node *p0 = new node;
        p0->data = p->data;
        p0->next = head->next;
        head->next = p0;
        p = p->next;
    }
    return *this;
}