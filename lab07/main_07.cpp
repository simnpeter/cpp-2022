#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>

using namespace std;
int main() {
    map<int,vector<int>> jatekos;
    ifstream file("bement.txt");
    string text;
    int jatek1, jatek2, pont;
    if(file.is_open()) {
        while (getline(file, text)) {
            //cout << text << endl;
            istringstream iss(text);
            iss >> jatek1;
            iss >> jatek2;
            iss >> pont;
        }
    }
    auto keres = jatekos.find(jatek1);
    if(keres != jatekos.end()){
        vector<int> temp;
        temp.push_back(pont);
        jatekos.insert({jatek1,temp});
    }
    else{
        keres->second.push_back(pont);
    }
    keres = jatekos.find(jatek2);
    if(keres != jatekos.end()){
        vector<int> temp;
        temp.push_back(pont);
        jatekos.insert({jatek2,temp});
    }
    else{
        keres->second.push_back(pont);
    }
    return 0;
}