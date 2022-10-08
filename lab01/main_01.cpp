#include <iostream>
#include <fstream>
#include "functions.h"

using namespace std;

int main() {
    cout << "1. feladat\n";
    for (int i = 0; i < 128; ++i) {
        cout << countBits(i) << "\n";
    }
    cout << "2. feladat\n";
    for (int i = 0; i < 35; ++i) {
        int n = 0;
        if(setBit(n, i)){
            cout<<i<<" ---> " << n <<endl;
        }else{
            cout<<"Impossible operation!" << endl;
        }
    }
    cout << "3. feladat\n";
    int n;
    cout << "Add meg n:";
    cin >> n;
    double array[n];
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
    }
    cout << mean(array, n);
    cout << "\n4. feladat\n";
    cout << stddev(array, n);
    cout << "\n5. feladat\n";
    pair<double, double> parok = max2(array,n);
    cout << parok.first << " " << parok.second;
    cout << "\n1. feladat\n" << isnum("1.2 2 alma haha 4") << "\n";
    cout << "2. feladat\n" << countWords("1 2 fa 3");
    string text = code("abcz ABCZ");
    cout << "\n3. feldat\n" << text << "\n";
    cout << "4. feladat\n" << decode(text);
    string myText;
    cout << "\n5. feladat\n";
    ifstream MyReadFile("bemenet.txt");

    // Use a while loop together with the getline() function to read the file line by line
    while (getline (MyReadFile, myText)) {
        // Output the text from the file
        cout << capitalizeWords(myText) << endl;
    }
    // Close the file
    MyReadFile.close();

    return 0;
}