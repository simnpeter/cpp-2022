//
// Created by SP on 2022. 11. 16..
//

#include "Szemely.h"

Szemely::Szemely(string firstName, string lastName, int year) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->birthDate = year;
}

void Szemely::print(ostream &os) {
    cout << "firstName: " << this->firstName <<"\nlastName: " << this->lastName << "\nbirthYear: " << this->birthDate << endl;
}

ostream &operator<<(ostream &os, Szemely szemely) {
    szemely.print(os);
    return os;
}
