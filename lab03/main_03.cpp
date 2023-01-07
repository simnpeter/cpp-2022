#include "Stack.h"
#include "List.h"

using namespace std;
int main() {
    List list = List();
    list.print();
    for (int i = 1; i < 12; ++i) {
        list.insertFirst(i);
    }
    list.print();
    if(list.exists(2)){
        cout << "exists\n";
    }
    else{
        cout << "do not exists\n";
    }
    if(list.exists(23)){
        cout << "exists\n";
    }
    else{
        cout << "do not exists\n";
    }
    cout << list.size() << endl;
    for (int i = 0; i < 4; ++i) {
        list.removeFirst();
    }
    list.print();
    list.remove(3, List::DeleteFlag::EQUAL);
    list.print();
    list.remove(9, List::DeleteFlag::GREATER);
    list.print();
    list.remove(9, List::DeleteFlag::LESS);
    list.print();
    list.~List();
    if(list.empty()){
        cout << "is empty\n";
    }
    list.print();/*
    Stack stack = Stack();
    if(stack.isEmpty()){
        cout << "stack is empty" << endl;
    }
    else{
        cout << "not empty" << endl;
    }
    stack.push(2);
    cout << stack.pop() << endl;
    if(stack.isEmpty()){
        cout << "stack is empty" << endl;
    }
    else{
        cout << "not empty" << endl;
    }
    for (int i = 1; i < 22; ++i) {
        stack.push(i*i);
    }
    if(stack.isEmpty()){
        cout << "stack is empty" << endl;
    }
    else{
        cout << "not empty" << endl;
    }
    for (int i = 0; i < 20; ++i) {
        cout << stack.pop() << endl;
    }
    if(stack.isEmpty()){
        cout << "stack is empty" << endl;
    }
    else{
        cout << "not empty" << endl;
    }
    cout << stack.pop() << endl;
    if(stack.isEmpty()){
        cout << "stack is empty" << endl;
    }
    else{
        cout << "not empty" << endl;
    }
    stack.~Stack();*/
    return 0;
}
