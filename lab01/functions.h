//
// Created by SP on 2022. 10. 07..
//

#ifndef CPP_2022_FUNCTIONS_H
#define CPP_2022_FUNCTIONS_H

#include "cmath"
#include <utility>
#include <cfloat>
#include <sstream>
#include <cstdlib>

using namespace std;

bool is_number(const std::string& s);
int countBits(int number);
bool setBit(int& number, int order);
double mean(double array[], int numElements);
double stddev(double array[], int numElements);
pair<double, double> max2(double array[], int numElements);
double isnum(const string& text);
int countWords(const string& text);
string code(string text);
string decode(string text);
string capitalizeWords(string text);

#endif //CPP_2022_FUNCTIONS_H
