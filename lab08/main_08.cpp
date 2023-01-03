#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cmath>
#include <random>

using namespace std;


int main() {
    vector<string> fruits {"melon", "strawberry", "raspberry","apple", "banana", "walnut", "lemon"};
    auto f1 = find_if(fruits.begin(), fruits.end(), [](const string& a){return a.find("berry") != -1;});
    if(f1 != fruits.end()){
        cout << "Found" << endl;
    }
    else{
        cout << "Not found" << endl;
    }
    vector<int> array{2, 4, 6, 8, 6};
    auto f2 = all_of(array.begin(), array.end(), [](int a){return a%2 == 0;});
    if(f2 == 1){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }
    for_each(array.begin(), array.end(), [](int &a){a*=2;cout << a << ' ';});
    cout << endl;
    vector<string> months {
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
    };
    auto f4 = count_if(months.begin(), months.end(), [](const string& a){return a.size() == 5;});
    cout << f4 << endl;
    vector<float> array2{12.3, 23.12, 1.23, 5.53, 23.43};
    sort(array2.begin(), array2.end(), [](float a, float b){return a>b;});
    for (auto a:array2) {
        cout << a << ' ';
    }
    cout << endl;
    sort(array2.begin(), array2.end(), greater<>());
    for (auto a:array2) {
        cout << a << ' ';
    }
    cout << endl;
    vector<pair<string,int>> homerseklet{ {"January",2},{"February",3}, {"March",4}, {"April",5}, {"May",2}, {"June",5},
                                          {"July",4}, {"August",6}, {"September",7}, {"October",9}, {"November",11}, {"December",23}};

    sort(homerseklet.begin(), homerseklet.end(), [](const pair<string,int>& a, const pair<string,int>& b){return a.second < b.second;});
    for (const auto& a:homerseklet ) {
        cout << a.first << ' ' << a.second << ", ";
    }
    cout << endl;
    vector<float> array3{-123.3, 1.12, -1.3, 5.23, 7.345, -4.23};
    sort(array3.begin(), array3.end(), [](float a, float b){return abs(a) < abs(b);});
    for (auto a:array3) {
        cout << a << ' ';
    }
    cout << endl;
    for_each(months.begin(), months.end(),[](string &a){return a.at(0)+=32;});
    for (auto a:months) {
        cout << a << ' ';
    }
    cout << endl;
    vector<char> abc{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','z'};
    shuffle(abc.begin(), abc.end(), std::mt19937(std::random_device()()));
    for (char &a: abc) {
        cout << a << ' ';
        cout << endl;
    }
    sort(months.begin(), months.end(), [abc](string &a, string &b)
    {return count(abc.begin(), abc.end(), a[0]) > count(abc.begin(), abc.end(), b[0]);});
    for (string &a : months){
        cout << a << ' ';
    }
    return 0;
}