//
// Created by SP on 2023. 01. 07..
//

#ifndef CPP_2022_GRADUATIONSERVICEIMPL_H
#define CPP_2022_GRADUATIONSERVICEIMPL_H

#include "GraduationService.h"
#include "GraduationDao.h"

class GraduationServiceImpl : public GraduationService {
private:
    GraduationDao *dao;

public:
    GraduationServiceImpl(GraduationDao *dao);

    Student findById(int id) const;

    double getResultByIdAndSubject(int id, const string &subject) const;
};
#endif //CPP_2022_GRADUATIONSERVICEIMPL_H
