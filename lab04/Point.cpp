//
// Created by SP on 2022. 10. 12..
//

#include <iostream>
#include "Point.h"
Point::Point(int x, int y){
    if((x>=0 && x<=M) && (y>=0 && y<=M)){
        this->x = x;
        this->y = y;
    }
}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}
double Point::distanceTO(const Point& point)const{
    return sqrt(pow((this->x-point.getX()), 2)+pow(this->y-point.getY(),2));
}

int Point::counter{0};

void Point::print() const {
    std::cout << "( "<<getX()<<","<<getY()<<" )"<<std::endl;
}