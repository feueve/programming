#include <iostream>
#include "func.h"

using namespace std;

int main() {
    Point p;
    cout << "Enter point (x y): ";
    readPoint(p);
    cout << "Point: ";
    printPoint(p);
    cout << endl;

    Circle c;
    cout << "\nEnter circle (center_x center_y radius): ";
    readCircle(c);
    cout << "Circle: ";
    printCircle(c);
    cout << "\nCircle perimeter: " << circlePerimeter(c);
    cout << "\nCircle area: " << circleArea(c) << endl;

    Square s;
    cout << "\nEnter square (topLeft_x topLeft_y side): ";
    readSquare(s);
    cout << "Square: ";
    printSquare(s);
    cout << "\nSquare perimeter: " << squarePerimeter(s);
    cout << "\nSquare area: " << squareArea(s) << endl;

    cout << "\nPoint in circle: " << isPointInCircle(p, c);
    cout << "\nPoint in square: " << isPointInSquare(p, s);

    cout << "\nPoint on circle: " << isPointOnCircle(p, c);
    cout << "\nPoint on square: " << isPointOnSquare(p, s);

    Circle c2;
    Square s2;
    cout << "\n\nEnter second circle: ";
    readCircle(c2);
    cout << "Enter second square: ";
    readSquare(s2);

    cout << "\nCircles intersect: " << circlesIntersect(c, c2);
    cout << "\nSquares intersect: " << squaresIntersect(s, s2);
    cout << "\nCircle and square intersect: " << circleSquareIntersect(c, s);

    cout << "\n\nCircle in circle: " << isCircleInCircle(c, c2);
    cout << "\nSquare in square: " << isSquareInSquare(s, s2);
    cout << "\nSquare in circle: " << isSquareInCircle(s, c);
    cout << "\nCircle in square: " << isCircleInSquare(c, s);

    return 0;
}