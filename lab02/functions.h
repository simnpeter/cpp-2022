//
// Created by SP on 2022. 10. 05..
//

#ifndef CPP_2022_FUNCTIONS_H
#define CPP_2022_FUNCTIONS_H
#include "Point.h"
#include <cmath>
#include <ctime>
#include <algorithm>

struct sPoint{
    double farest;
    Point farestp;
};

double distance(const Point& a, const Point& b);
double sqrDistance(Point a, Point b);
bool isSquare(const Point& a, const Point& b, const Point& c, const Point& d);
void testIsSquare(const char * filename);
Point* createArray(int numPoints);
void printArray(Point* points, int numPoints);
pair<Point, Point> closestPoints(Point* points, int numPoints);
pair<Point, Point> farthestPoints(Point* points, int numPoints);
void sortPoints(Point* points, int numPoints);
bool myFunction(Point a, Point b);
Point* farthestPointsFromOrigin(Point* points, int numPoints);
void deletePoints(Point* points);
bool myFunction2(sPoint a, sPoint b);

#endif //CPP_2022_FUNCTIONS_H
