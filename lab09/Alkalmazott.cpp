//
// Created by SP on 2022. 11. 16..
//

#include "Alkalmazott.h"

int Alkalmazott::idnak{0};
Alkalmazott::Alkalmazott(string firstName, string lastName, int year, string munkakor)
    : Szemely(firstName, lastName, year) {
    this->position = munkakor;
    this->id = ++idnak;
}

void Alkalmazott::print(ostream &os) {
    cout << this->id << " " << this->firstName <<" " << this->lastName
    << " " << this->position << endl;
}

int Alkalmazott::getId() const {
    return this->id;
}

string Alkalmazott::getPosition() const {
    return this->position;
}
