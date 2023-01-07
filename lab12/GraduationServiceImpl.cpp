//
// Created by SP on 2023. 01. 07..
//

#include "GraduationServiceImpl.h"
GraduationServiceImpl::GraduationServiceImpl(GraduationDao *dao) : dao(dao) {}

Student GraduationServiceImpl::findById(int id) const {
    return dao->findById(id);
}

double GraduationServiceImpl::getResultByIdAndSubject(int id, const string &subject) const {
    Student student = dao->findById(id);
    return student.getGrade(subject);
}