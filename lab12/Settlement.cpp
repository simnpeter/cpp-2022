//
// Created by SP on 2023. 01. 07..
//

#include "Settlement.h"
Settlement::Settlement(const string &name, const string &county, int population) :
name(name), county(county), population(population) {}

const string &Settlement::getName() const {
    return name;
}

const string &Settlement::getCounty() const {
    return county;
}

int Settlement::getPopulation() const {
    return population;
}

void Settlement::setPopulation(int population) {
    Settlement::population = population;
}

void Settlement::setName(const string &name) {
    Settlement::name = name;
}

void Settlement::setCounty(const string &county) {
    Settlement::county = county;
}

ostream &operator<<(ostream &os, const Settlement &settlement){
    os<<settlement.name<<", "<<settlement.county<<": "<<settlement.population<<endl;
    return os;
}