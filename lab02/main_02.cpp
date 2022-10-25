#include "functions.h"

using namespace std;

int main(int argc, char** argv) {
    Point p1(2,3);
    p1.print();
    Point p2(100, 200);
    p2.print();
    Point * pp1 = new Point(300, 400);
    Point * pp2 = new Point(500, 1000);
    pp1->print();
    pp2->print();
    //feladat 4
    cout << distance(p1, p2) << endl;
    delete pp1;
    delete pp2;
    //feladat 5
    Point d1 = { 20, 10 }, d2 = { 10, 20 },  d3 = { 20, 20 }, d4 = { 10, 10 };
    d1.print();
    d2.print();
    d3.print();
    d4.print();
    isSquare(d1, d2, d3, d4) ? cout << "Yes\n" : cout << "No\n";
    //feladat 6
    testIsSquare("bemenet.txt");
    //feladat 7
    int n;
    cin >> n;
    Point* points = createArray(n);
    //feladat 8
    printArray(points,n);
    cout << endl;
    //feladat 9
    pair<Point, Point> ppoints = closestPoints(points, n);
    ppoints.first.print();
    ppoints.second.print();
    cout << endl;
    //feladat 10
    ppoints = farthestPoints(points, n);
    ppoints.first.print();
    ppoints.second.print();
    //feladat 11
    cout << endl << "\nAfter sort\n";
    sortPoints(points, n);
    //feladat 12
    cout << "\nFarest points\n" ;
    Point* point = farthestPointsFromOrigin(points, n);
    //feladat 13
    deletePoints(points);
    deletePoints(point);
    return 0;
}
