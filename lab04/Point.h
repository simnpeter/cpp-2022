//
// Created by SP on 2022. 10. 12..
//

#ifndef CPP_2022_POINT_H
#define CPP_2022_POINT_H
#include <cmath>
#define M 2000


class Point {
private:
    int x, y;
public:
    Point(int x=0, int y=0);
    int getX() const;
    int getY() const;
    void print() const;
    double distanceTO(const Point& point)const;
};


#endif //CPP_2022_POINT_H
