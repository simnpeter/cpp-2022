//
// Created by SP on 2022. 12. 22..
//

#include "huffman.h"

huffman::huffman(string file) {
    myifstream be(file);
    for (int i = 0; i < be.filesize(); ++i) {
        if(be[i] <= 90 && be[i] >= 65){
            auto ind = freq.find(be[i]);
            if(ind != freq.end()){
                ind->second++;
                continue;
            }
            freq.insert(pair<char,int>{be[i],1});
        }
    }
    for (auto a : freq) {
        cout << a.first << "  " << a.second << endl;
    }
}
