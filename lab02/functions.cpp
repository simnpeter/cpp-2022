//
// Created by SP on 2022. 10. 05..
//

#include "functions.h"
#include <fstream>
#include <sstream>

double distance(const Point &a, const Point &b) {
    return sqrt(pow((a.getX()-b.getX()), 2)+pow(a.getY()-b.getY(),2));
}

bool isSquare(const Point &a, const Point &b, const Point &c, const Point &d) {
    int d2 = (int)pow(distance(a, b),2);
    int d3 = (int)pow(distance(a, c),2);
    int d4 = (int)pow(distance(a, d),2);

    if (d2 == 0 || d3 == 0 || d4 == 0)
        return false;
    if (d2 == d3 && 2 * d2 == d4 && 2 * (int)pow(distance(b, d),2) == (int)pow(distance(b, c),2)) {
        return true;
    }
    if (d3 == d4 && 2 * d3 == d2 && 2 * (int)pow(distance(c, b),2) == (int)pow(distance(c, d),2)) {
        return true;
    }
    if (d2 == d4 && 2 * d2 == d3 && 2 * (int)pow(distance(b, c),2) == (int)pow(distance(b, d),2)) {
        return true;
    }
    return false;
}

void testIsSquare(const char *filename) {
    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cout << "Could not open the file - '"
             << filename << "'" << endl;
        exit(0);
    }
    string text;
    Point *a, *b, *c, *d;
    int a1, a2;
    while (getline(input_file, text)) {
        istringstream nums(text);
        nums >> a1;
        nums >> a2;
        a = new Point(a1, a2);
        nums >> a1;
        nums >> a2;
        b = new Point(a1, a2);
        nums >> a1;
        nums >> a2;
        c = new Point(a1, a2);
        nums >> a1;
        nums >> a2;
        d = new Point(a1, a2);
        a->print();
        b->print();
        c->print();
        d->print();
        isSquare(*a, *b, *c, *d) ? cout << "Yes" << endl : cout << "No" << endl;
    }
    delete a;
    delete b;
    delete c;
    delete d;
    cout << endl;
    input_file.close();
}

Point* createArray(int numPoints){
    srand((unsigned)time(0));
    Point * points = new Point[numPoints];
    if(!points){
        exit(-1);
    }
    for (int i = 0; i < numPoints; ++i) {
        points[i] = Point((rand()%2000), (rand()%2000));
    }
    return points;
}

void printArray(Point *points, int numPoints) {
    for (int i = 0; i < numPoints; ++i) {
        points[i].print();
    }
}

pair<Point, Point> closestPoints(Point *points, int numPoints) {
    pair<Point, Point> ppair;
    double mintav = 2000;
    for (int i = 0; i < numPoints; ++i) {
        for (int j = 0; j < numPoints; ++j) {
            if(i == j){
                continue;
            }
            double dist = distance(points[i], points[j]);
            if(mintav > dist){
                ppair.first = points[i];
                ppair.second = points[j];
                mintav = dist;
            }
        }
    }
    return ppair;
}

pair<Point, Point> farthestPoints(Point *points, int numPoints) {
    pair<Point, Point> ppair;
    double mintav = 0;
    for (int i = 0; i < numPoints; ++i) {
        for (int j = 0; j < numPoints; ++j) {
            if(i == j){
                continue;
            }
            double dist = distance(points[i], points[j]);
            if(mintav < dist){
                ppair.first = points[i];
                ppair.second = points[j];
                mintav = dist;
            }
        }
    }
    return ppair;
}

void sortPoints(Point *points, int numPoints) {
    sort(points, points+numPoints, myFunction);
    printArray(points, numPoints);
}

bool myFunction(Point a, Point b) {
    return a.getX()<b.getX();
}

void deletePoints(Point *points) {
    delete [] points;
}

Point *farthestPointsFromOrigin(Point *points, int numPoints) {
    int j=0;
    sPoint sorting[10];
    Point origo(0,0);
    for (int i = 0; i < numPoints; ++i) {
        double dist = distance(origo,points[i]);
        if( dist > sorting[j].farest){
            if(j == 10){
                sorting[j-1].farest = dist;
                sorting[j-1].farestp = points[i];
                sort(begin(sorting), end(sorting), myFunction2);
            }
            else if (j < 10) {
                sorting[j].farest = dist;
                sorting[j].farestp = points[i];
                ++j;
                if(j == 10){
                    sort(begin(sorting), end(sorting), myFunction2);
                }
            }
        }
    }
    auto* point = new Point[j];
    for (int i = 0; i < j; ++i) {
        point[i] = sorting[i].farestp;
    }
    printArray(point,j);
    return point;
}

bool myFunction2(sPoint a, sPoint b) {
    return a.farest > b.farest;
}
