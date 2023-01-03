//
// Created by SP on 2022. 11. 16..
//

#ifndef CPP_2022_CEG_H
#define CPP_2022_CEG_H
#include "Manager.h"

class Ceg {
protected:
    vector<Manager> Managerek;
    vector<Alkalmazott*> Alkalmazottak;
public:
    void addAlkalmazott(Alkalmazott *alk);
    void removeAlkalmazott(int id);
    void addToManager(Alkalmazott* alk);
    void removeFromManager(int id);
    void printAll(ostream& out);
    void printManager(ostream& out);
};


#endif //CPP_2022_CEG_H
