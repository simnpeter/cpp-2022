//
// Created by SP on 2022. 10. 07..
//

#include "Stack.h"


void Stack::push(int e) {
    this->verem.insertFirst(e);
}

int Stack::pop() {
    return this->verem.removeFirst();
}

bool Stack::isEmpty() const {
    return this->verem.empty();
}

Stack::~Stack() {
    this->verem.~List();
}

