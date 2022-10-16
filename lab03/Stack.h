//
// Created by SP on 2022. 10. 07..
//

#ifndef CPP_2022_STACK_H
#define CPP_2022_STACK_H

#include "List.h"
class Stack {
public:
    ~Stack();
    void push(int e);
    int pop();
    bool isEmpty() const;
private:
    List verem = List();
};


#endif //CPP_2022_STACK_H
