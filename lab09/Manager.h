//
// Created by SP on 2022. 11. 16..
//

#ifndef CPP_2022_MANAGER_H
#define CPP_2022_MANAGER_H
#include "Alkalmazott.h"
#include <vector>

using namespace std;
class Manager : public Alkalmazott{
protected:
    vector<Alkalmazott*> alkalmazottak;
public:
    Manager(string lastName, string firstName, int year, string munkakor);
    static const string MANAGER_MUNKAKOR;
    void addAlkalmazott(Alkalmazott* alkalmazott);
    void deleteAlkalmazott(int id);
    int beosztottakSzama();
    virtual void print(ostream& os) override;
};


#endif //CPP_2022_MANAGER_H
