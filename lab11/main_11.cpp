#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

string tisztit(string szo){
    for (int i = 0; i < szo.length(); ++i) {
        if(szo.at(i) <= 90 && szo.at(i) >= 65){
            szo.at(i)+=32;
        }
        if(szo.at(i) < 97 || szo.at(i) > 122){
            szo.erase(i);
        }
    }
    return szo;
}

int meddig(pair<const basic_string<char>, vector<int>> a, int i){
    while(1){
        if(i+1 < a.second.size() && a.second[i]+1 == a.second[i+1]){
            i++;
        }
        else{
            return i;
        }
    }
}

int main() {
    map<string,vector<int>> szavak;
    ifstream file("bemenet.txt");
    string text;
    int line = 0;
    bool valtas = false;
    if(file.is_open()) {
        while (getline(file, text)) {
            //cout << text << endl;
            int szodb = 0;
            istringstream iss(text);
            string words;
            while(iss >> words){
                szodb++;
            }
            if(szodb==0){
                continue;
            }
            if(szodb==1){
                cout << words << endl;
                szavak.insert(pair<string,int>{words,0});
            }
            else{
                ++line;
                valtas = true;
                istringstream findw(text);
                while(findw >> words){
                    words = tisztit(words);
                    auto ind = szavak.find(words);
                    if(ind != szavak.end()){
                        ind->second.push_back(line);
                    }
                }
            }
        }
        for (auto a:szavak) {
            for(int i = 0 ; i < a.first.size() ; i++){
                cout << a.first[i];
            }
            for(int i = 0 ; i < a.second.size(); i++){
                if(i-1 >= 0 && a.second[i] == a.second[i-1]){
                    continue;
                }
                if(i != 0){
                    cout << ", " << a.second[i];
                }
                else{
                    cout << ' ' << a.second[i];
                }
                if( i+1 != a.second.size() && a.second[i]+1 == a.second[i+1]){
                    cout << "-";
                    i = meddig(a, i);
                    cout << a.second[i];
                }
            }
            cout << endl;
        }
    }else{
        cout << "Error in file opening" << endl;
    }
    return 0;
}
