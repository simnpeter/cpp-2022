//
// Created by SP on 2022. 11. 16..
//

#ifndef CPP_2022_SZEMELY_H
#define CPP_2022_SZEMELY_H
#include <iostream>

using namespace std;
class Szemely {
protected:
    string firstName;
    string lastName;
    int birthDate;
public:
    Szemely(string fistName, string lastName, int year);
    virtual void print(ostream & os);
};
ostream& operator << (ostream& os, Szemely szemely);


#endif //CPP_2022_SZEMELY_H
