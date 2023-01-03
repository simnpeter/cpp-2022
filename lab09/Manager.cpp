//
// Created by SP on 2022. 11. 16..
//

#include <algorithm>
#include "Manager.h"

const string Manager::MANAGER_MUNKAKOR = "manager";

Manager::Manager(string lastName, string firstName, int year, string munkakor)
    : Alkalmazott(lastName, firstName, year, munkakor) {
}

void Manager::print(ostream& os) {
    cout << "Manager " << id << " " << firstName << " " << lastName << " beosztottjai:\n";
    for (auto a: alkalmazottak) {
        cout << "\tAlkalmazott ";
        a->print(os);
    }
}

void Manager::addAlkalmazott(Alkalmazott *alkalmazott) {
    if(remove(alkalmazottak.begin(), alkalmazottak.end(), alkalmazott) == alkalmazottak.end()) {
        alkalmazottak.emplace_back(alkalmazott);
    }
}

void Manager::deleteAlkalmazott(int id) {
    for (auto a:alkalmazottak) {
        if(id == a->getId()){
            auto valt = remove(alkalmazottak.begin(), alkalmazottak.end(), a);
            alkalmazottak.erase(valt);
            return;
        }
    }
}

int Manager::beosztottakSzama() {
    return alkalmazottak.size();
}
