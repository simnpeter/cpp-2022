//
// Created by SP on 2022. 10. 05..
//

#include "Point.h"
#include "../lab04/Point.h"

Point::Point(int x, int y) {
    if( x >= 0 && x <= 2000 && y >= 0 && y <= 2000){
        this->x = x;
        this->y = y;
    }
    else{
        this->x = 0;
        this->y = 0;
    }
}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

void Point::print() const {
    cout << "( "<<getX()<<","<<getY()<<" )"<<endl;
}