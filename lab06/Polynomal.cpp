//
// Created by SP on 2022. 10. 26..
//

#include "Polynomal.h"

Polynomial::Polynomial(int degree, const double *coefficients) {
    this->capacity = degree + 1;
    this->coefficients = new double [this->capacity];
    for (int i = 0; i < this->capacity; ++i) {
        this->coefficients[i] = coefficients[i];
    }
}

Polynomial::Polynomial(const Polynomial &that) {
    this->capacity = that.capacity;
    this->coefficients = new double[this->capacity];
    for (int i = 0; i < this->capacity; ++i) {
        this->coefficients[i] = that.coefficients[i];
    }
}

Polynomial::Polynomial(Polynomial &&that) {
    if(this != &that) {
        this->capacity = that.capacity;
        this->coefficients = that.coefficients;

        that.capacity = 0;
        that.coefficients = nullptr;
    }
}

Polynomial::~Polynomial() {
    this->capacity = 0;
    delete [] this->coefficients;
}

int Polynomial::degree() const {
    return (this->capacity-1);
}

Polynomial Polynomial::derivative() const {
    Polynomial derivate(this->capacity-2, this->coefficients);
    int degree = derivate.capacity;
    for (int i = 0; i < derivate.capacity-1; ++i) {
        derivate.coefficients[i] *= (degree-i);
    }
    return derivate;
}

double Polynomial::operator[](int index) const {
    return this->coefficients[index];
}

Polynomial operator-(const Polynomial &a) {
    Polynomial temp(a);
    for (int i = 0; i < a.capacity; ++i) {
        temp.coefficients[i] *= -1;
    }
    return temp;
}

Polynomial operator+(const Polynomial &a, const Polynomial &b) {
    int maxCapacity = max(a.capacity, b.capacity);
    auto newCoefficients = new double[maxCapacity];
    if(a.capacity > b.capacity){
        int bIndex = b.capacity-1;
        for (int i = a.capacity-1; i >=0 ; --i) {
            if(bIndex >= 0){
                newCoefficients[i] = a.coefficients[i]+b.coefficients[bIndex];
                --bIndex;
            }
            else{
                newCoefficients[i] = a.coefficients[i];
            }
        }
    }
    if(a.capacity < b.capacity){
        int aIndex = a.capacity-1;
        for (int i = b.capacity-1; i >=0 ; --i) {
            if(aIndex >= 0){
                newCoefficients[i] = b.coefficients[i]+a.coefficients[aIndex];
                --aIndex;
            }
            else{
                newCoefficients[i] = b.coefficients[i];
            }
        }
    }
    Polynomial temp(maxCapacity-1, newCoefficients);
    delete [] newCoefficients;
    return temp;
}

ostream &operator<<(ostream &out, const Polynomial &what) {
    int i = 0;
    for (i = 0; i < what.capacity-1; ++i) {
        out << what.coefficients[i] << "x^" << what.capacity-1-i << " + ";
    }
    out << what.coefficients[i] << endl;
    return out;
}

Polynomial operator-(const Polynomial &a, const Polynomial &b) {
    int maxCapacity = max(a.capacity, b.capacity);
    auto newCoefficients = new double[maxCapacity];
    if(a.capacity > b.capacity){
        int bIndex = b.capacity-1;
        for (int i = a.capacity-1; i >=0 ; --i) {
            if(bIndex >= 0){
                newCoefficients[i] = a.coefficients[i]-b.coefficients[bIndex];
                --bIndex;
            }
            else{
                newCoefficients[i] = a.coefficients[i];
            }
        }
    }
    if(a.capacity < b.capacity){
        int aIndex = a.capacity-1;
        for (int i = b.capacity-1; i >=0 ; --i) {
            if(aIndex >= 0){
                newCoefficients[i] = a.coefficients[aIndex]-b.coefficients[i];
                --aIndex;
            }
            else{
                newCoefficients[i] = b.coefficients[i];
            }
        }
    }
    Polynomial temp(maxCapacity-1, newCoefficients);
    delete [] newCoefficients;
    return temp;
}

Polynomial operator*(const Polynomial &a, const Polynomial &b) {
    int maxCapacity = a.capacity + b.capacity - 1;
    auto *newCoefficients = new double[maxCapacity];
    // valamiert memoria szemet van a newcoefficientsbe ha nem nullazom ki
    for (int i = 0; i < maxCapacity; ++i) {
        newCoefficients[i] = 0;
    }
    for (int i = 0; i < a.capacity; ++i) {
        for (int j = 0; j < b.capacity; ++j) {
            newCoefficients[i + j] += a.coefficients[i] * b.coefficients[j];
        }
    }
    Polynomial temp(maxCapacity - 1, newCoefficients);
    delete[] newCoefficients;
    return temp;
}

double Polynomial::evaluate(double x) const {
    
}

