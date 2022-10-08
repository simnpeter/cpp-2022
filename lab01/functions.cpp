//
// Created by SP on 2022. 10. 07..
//

#include <iostream>
#include "functions.h"


int countBits(int number) {
    int sum = 0;
    while(number != 0){
        sum += number & 1;
        number = number >> 1;
    }
    return sum;
}

bool setBit(int &number, int order) {
    if(order == 0) return true;
    if(order > 31 || order < 0) return false;
    --order;
    number |= 1UL << order;
    return true;
}

double mean(double *array, int numElements) {
    if(numElements == 0) return NAN;
    double sum = 0;
    for (int i = 0; i < numElements; ++i) {
        sum += array[i];
    }
    return sum/numElements;
}

double stddev(double *array, int numElements) {
    if(numElements == 0) return NAN;
    double avg = mean(array, numElements);
    double eredmeny, res = 0;
    for (int i = 0; i < numElements; ++i) {
        eredmeny = (array[i]-avg);
        if(eredmeny < 0) eredmeny*=-1;
        eredmeny *= eredmeny;
        res += eredmeny;
    }
    res /= (numElements);
    return sqrt(res);
}

pair<double, double> max2(double *array, int numElements) {
    pair<double, double> parok;
    if(numElements <= 0 ) {
        parok.first = parok.second = NAN;
        return parok;
    }
    else if(numElements == 1){
        parok.first = array[0];
        parok.second = NAN;
        return parok;
    }
    parok.first = parok.second = -DBL_MIN;
    for (int i = 0; i < numElements; ++i) {
        if (array[i] > parok.first){
            parok.second = parok.first;
            parok.first = array[i];
        }
        else if(array[i] > parok.second) parok.second = array[i];
    }
    return parok;
}

double isnum(const string& text) {
    istringstream iss(text);
    double sum = 0;
    string num;
    while(iss >> num){
        if(is_number(num)){
            sum += stod(num);
        }
    }
    return sum;
}

int countWords(const string& text) {
    istringstream iss(text);
    string words;
    int count = 0;
    while(iss >> words){
        count++;
    }
    return count;
}

bool is_number(const std::string& s)
{
    char* end = nullptr;
    double val = strtod(s.c_str(), &end);
    return end != s.c_str() && *end == '\0' && val != HUGE_VAL;
}

string code(string text) {
    int i=0;
    while(text[i] != '\0'){
        if((text[i] >= 65 && text[i] <=90) || (text[i] >= 97 && text[i] <= 122)){
            if(text[i] == 90 || text[i] == 122) text[i] -= 25;
            else text[i]++;
        }
        i++;
    }
    return text;
}

string decode(string text) {
    int i=0;
    while(text[i] != '\0'){
        if((text[i] >= 65 && text[i] <=90) || (text[i] >= 97 && text[i] <= 122)){
            if(text[i] == 65 || text[i] == 97) text[i] += 25;
            else text[i]--;
        }
        i++;
    }
    return text;
}

string capitalizeWords(string text) {
    int i = 0;
    while(text[i] != '\0'){
        if(text[i-1] == ' ' || i == 0){
            if(text[i] >= 97 && text[i] <= 122) text[i] -= 32;
        }
        else{
            if(text[i] >= 65 && text[i] <=90) text[i] +=32;
        }
        i++;
    }
    return text;
}