#include "myifstream.h"
#include "huffman.h"

using namespace std;
int main() {
    /*
    myifstream f("be.txt");
    for( int i=0; i <f.filesize(); ++i){
        cout << f[i] << endl;
    }
    cout << endl;
    */
    huffman huff("be.txt");
    return 0;
}