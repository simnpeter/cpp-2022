//
// Created by SP on 2022. 12. 21..
//

#include <fstream>
#include "myifstream.h"

myifstream::myifstream(string filename) {
    ifstream in(filename);
    if(in.is_open()) {
        string line;
        while (getline(in, line)) {
            text += ' ' + line;
        }
    }else{
        cout << "Error in file opening" << endl;
    }
}

char myifstream::operator[](int index) {
    return text.at(index);
}

int myifstream::filesize() {
    return text.length();
}
