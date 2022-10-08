//
// Created by SP on 2022. 10. 05..
//

#include "List.h"

using namespace std;

List::List() {
    this->first = new Node(0, nullptr);
}

List::~List() {
    Node *temp = this->first;
    while(temp)
    {
        temp = temp->next;
        delete this->first;
        this->first = temp;
    }
    temp = nullptr;
}

bool List::exists(int d) const {
    Node *temp = this->first;
    while(temp) {
        if(temp->value == d) return true;
        temp = temp->next;
    }
    temp = nullptr;
    return false;
}

int List::size() const {
    int i = 1;
    if(!this->first)return 0;
    Node* temp = this->first;
    while (temp->next){
        ++i;
        temp = temp->next;
    }
    return i;
}

bool List::empty() const {
    return !this->first;
}

void List::insertFirst(int d) {
    Node* newNode = new Node(d, this->first);
    this->first = newNode;
}

int List::removeFirst() {
    if(empty()){
        throw invalid_argument("The list is allready empty\n");
    }
    int d = this->first->value;
    Node *temp = this->first->next;
    this->first = temp;
    temp = nullptr;
    return d;
}

void List::print() const {
    if(empty()){
        cout << "List is empty\n";
        return;
    }
    Node* temp = this->first;
    while (temp){
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
    temp = nullptr;
}

void List::remove(int d, List::DeleteFlag df) {
    Node* temp = this->first;
    switch (df) {
        case DeleteFlag::EQUAL:
            if(temp->value == d){
                removeFirst();
                return;
            }
            while(temp->next){
                if(temp->next->value == d){
                    Node* temp2 = temp->next->next;
                    delete temp->next;
                    temp->next = temp2;
                    return;
                }
                temp= temp->next;
            }
            cout << "Cant find equal value\n";
            return;
        case DeleteFlag::LESS:
            if(temp->value < d){
                removeFirst();
                return;
            }
            while(temp->next){
                if(temp->next->value < d){
                    Node* temp2 = temp->next->next;
                    delete temp->next;
                    temp->next = temp2;
                    return;
                }
                temp= temp->next;
            }
            cout << "Cant find less value\n";
            return;
        case DeleteFlag::GREATER:
            if(temp->value > d){
                removeFirst();
                return;
            }
            while(temp->next){
                if(temp->next->value > d){
                    Node* temp2 = temp->next->next;
                    delete temp->next;
                    temp->next = temp2;
                    return;
                }
                temp= temp->next;
            }
            cout << "Cant find greater value\n";
            return;
        default:
            return;
    }
}


