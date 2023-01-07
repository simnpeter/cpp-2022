//
// Created by SP on 2023. 01. 07..
//

#include "Student.h"

Student::Student(int id, const string &firstName, const string &lastName) : id(id), firstName(firstName),
                                                                            lastName(lastName) {}

const map<string, double> &Student::getGrades() const {
    return grades;
}

void Student::computeAverage() {
    double sum = 0;
    for (auto &[key, value]: this->grades) {
        if (value < 5) {
            return;
        }
        sum += value;
    }
    sum = sum / this->grades.size();
    if (sum >= 6) {
        this->average = sum;
    }
}

ostream &operator<<(ostream &os, const Student &student) {
    os << student.id << ". " << student.firstName << " " << student.lastName << endl;
    for (auto &e: student.grades) {
        os << "\t" << e.first <<" --> " << e.second << endl;
    }
    return os;
}