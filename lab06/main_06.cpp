#include "Polynomal.h"

using namespace std;
int main() {
    /*int n;
    cin >> n;
    double *temp = new double [n];
    for (int i = 0; i < n; ++i) {
        cin >> temp[i];
    }*/
    Polynomial polinom(4, new double [5]{1 ,2,3,4,5});
    Polynomial polynom2(3, new double [4]{1, 3, 4, 5});
    cout << polinom;
    Polynomial derivate = polinom.derivative();
    cout << derivate;
    Polynomial osszeadas = polinom +polynom2;
    cout << polinom;
    cout << polynom2;
    cout << osszeadas;
    Polynomial kivonas = polinom-polynom2;
    cout << kivonas;
    Polynomial szorzas = polinom*polynom2;
    cout << szorzas;
    return 0;
}