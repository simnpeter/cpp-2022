//
// Created by SP on 2022. 11. 16..
//

#ifndef CPP_2022_ALKALMAZOTT_H
#define CPP_2022_ALKALMAZOTT_H
#include "Szemely.h"

class Alkalmazott : public Szemely{
protected:
    string position;
    int id;
    static int idnak;
public:
    Alkalmazott(string firstName, string lastName, int year, string munkakor);
    virtual void print(ostream &os) override;
    int getId() const;
    string getPosition() const;
};


#endif //CPP_2022_ALKALMAZOTT_H
