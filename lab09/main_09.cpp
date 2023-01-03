#include "Ceg.h"

int main() {
    auto * alkalmazott = new Alkalmazott("xy", "zm", 2017, "nem");
    auto* manager = new Manager("xy", "zm", 2017, "Manager");
    Ceg ceg;
    ceg.addAlkalmazott(dynamic_cast<Alkalmazott*> (manager));
    ceg.addAlkalmazott(alkalmazott);
    //dynamic cast
    vector<Alkalmazott*> alkalmazottak;
    alkalmazottak.push_back(alkalmazott);
    alkalmazottak.push_back(dynamic_cast<Alkalmazott*> (manager));
    for (auto a:alkalmazottak) {
        if(a->getPosition() == "Manager") {
            auto newa = dynamic_cast<Manager*> (a);
            newa->addAlkalmazott(alkalmazott);
            newa->print(cout);
        }
    }
    for (auto a:alkalmazottak) {
        if(a->getPosition() == "Manger") {
            auto newa = dynamic_cast<Manager *> (a);
            newa->print(cout);
        }
    }
}