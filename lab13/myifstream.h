//
// Created by SP on 2022. 12. 21..
//

#ifndef CPP_2022_MYIFSTREAM_H
#define CPP_2022_MYIFSTREAM_H
#include <iostream>

using namespace std;
class myifstream {
private:
    string text;
public:
    myifstream(string filename);
    char operator [] (int index);
    int filesize();
};


#endif //CPP_2022_MYIFSTREAM_H
