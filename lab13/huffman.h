//
// Created by SP on 2022. 12. 22..
//

#ifndef CPP_2022_HUFFMAN_H
#define CPP_2022_HUFFMAN_H

#include <string>
#include <map>
#include "myifstream.h"

using namespace std;
class huffman {
private:
    map<char, int> freq;
    struct MinHeapNode {
        char data;
        unsigned freq;
        struct MinHeapNode *left, *right;
    };

    struct MinHeap {
        unsigned size;
        unsigned capacity;
        struct MinHeapNode** array;
    };
    MinHeap* minheap;
public:
    huffman(string file);
};


#endif //CPP_2022_HUFFMAN_H
