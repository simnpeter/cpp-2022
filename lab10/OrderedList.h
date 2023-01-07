//
// Created by SP on 2022. 11. 23..
//

#ifndef CPP_2022_ORDEREDLIST_H
#define CPP_2022_ORDEREDLIST_H
#include <functional>
#include <iostream>
using namespace std;
// Class definition
template <class T, class LessComp = less<T>, class Equal = equal_to<T> >
class OrderedList{
private:
    struct Node{
        T value;
        Node* next;
        Node(T t, Node* node):value(t), next(node){}
    };
    Node* first;
    int numElements;
public:
    OrderedList();
    ~OrderedList();
    bool isEmpty();
    void insert(T& t);
    void remove(T& t);
    int size() const;
    bool find(T& t) const;
    void listItems(ostream& os);
};

template < class T, class LessComp, class Equal>
OrderedList<T, LessComp, Equal>::OrderedList() {
    first = nullptr;
    numElements = 0;
}

template <class T, class LessComp, class Equal>
OrderedList<T, LessComp, Equal>::~OrderedList() {
    Node* temp = first;
    while( temp ){
        delete first;
        first = temp->next;
    }
    temp = nullptr;
    first = nullptr;
}

template <class T, class LessComp, class Equal>
bool OrderedList<T, LessComp, Equal>::isEmpty() {
    return !this->numElements;
}

template <class T, class LessComp, class Equal>
int OrderedList<T, LessComp, Equal>::size() const {
    return this->numElements;
}

template <class T, class LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::listItems(std::ostream &os) {
    Node* temp = this->first;
    while (temp){
        os << temp->value << ' ';
        temp = temp->next;
    }
    temp = nullptr;
    os << endl;
}

template <class T, class LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::insert(T &t) {
    Node* newNode = new Node(t, nullptr);
    if(this->isEmpty()){
        this->first = newNode;
        return;
    }
    Node* tempfirst = this->first;

}
#endif //CPP_2022_ORDEREDLIST_H
