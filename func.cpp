#include "func.h"
#include <cmath>
#include <iostream>

const double EPS = 1e-5;
const double PI = 3.141592653589793;

double distance(const Point& a, const Point& b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

bool equal(double a, double b) {
    return fabs(a - b) < EPS;
}

void readPoint(Point& p) {
    std::cin >> p.x >> p.y;
}

void printPoint(const Point& p) {
    std::cout << "(" << p.x << ", " << p.y << ")";
}

void readCircle(Circle& c) {
    readPoint(c.center);
    std::cin >> c.radius;
}

void printCircle(const Circle& c) {
    std::cout << "Center: ";
    printPoint(c.center);
    std::cout << ", Radius: " << c.radius;
}

double circlePerimeter(const Circle& c) {
    return 2 * PI * c.radius;
}

double circleArea(const Circle& c) {
    return PI * c.radius * c.radius;
}

void readSquare(Square& s) {
    readPoint(s.topLeft);
    std::cin >> s.side;
}

void printSquare(const Square& s) {
    std::cout << "TopLeft: ";
    printPoint(s.topLeft);
    std::cout << ", Side: " << s.side;
}

double squarePerimeter(const Square& s) {
    return 4 * s.side;
}

double squareArea(const Square& s) {
    return s.side * s.side;
}

bool isPointInCircle(const Point& p, const Circle& c) {
    return distance(p, c.center) < c.radius - EPS;
}

bool isPointInSquare(const Point& p, const Square& s) {
    return (p.x > s.topLeft.x + EPS) &&
           (p.x < s.topLeft.x + s.side - EPS) &&
           (p.y < s.topLeft.y - EPS) &&
           (p.y > s.topLeft.y - s.side + EPS);
}

bool isPointOnCircle(const Point& p, const Circle& c) {
    return equal(distance(p, c.center), c.radius);
}

bool isPointOnSquare(const Point& p, const Square& s) {
    bool onVertical = (equal(p.x, s.topLeft.x) || equal(p.x, s.topLeft.x + s.side)) &&
                      (p.y <= s.topLeft.y + EPS) && (p.y >= s.topLeft.y - s.side - EPS);
    bool onHorizontal = (equal(p.y, s.topLeft.y) || equal(p.y, s.topLeft.y - s.side)) &&
                        (p.x >= s.topLeft.x - EPS) && (p.x <= s.topLeft.x + s.side + EPS);
    return onVertical || onHorizontal;
}

bool circlesIntersect(const Circle& c1, const Circle& c2) {
    double d = distance(c1.center, c2.center);
    return d < c1.radius + c2.radius + EPS &&
           d > fabs(c1.radius - c2.radius) - EPS;
}

bool squaresIntersect(const Square& s1, const Square& s2) {
    bool xOverlap = s1.topLeft.x < s2.topLeft.x + s2.side + EPS &&
                    s2.topLeft.x < s1.topLeft.x + s1.side + EPS;
    bool yOverlap = s1.topLeft.y > s2.topLeft.y - s2.side - EPS &&
                    s2.topLeft.y > s1.topLeft.y - s1.side - EPS;
    return xOverlap && yOverlap;
}

bool circleSquareIntersect(const Circle& c, const Square& s) {
    Point corners[4] = {
            s.topLeft,
            {s.topLeft.x + s.side, s.topLeft.y},
            {s.topLeft.x, s.topLeft.y - s.side},
            {s.topLeft.x + s.side, s.topLeft.y - s.side}
    };

    for (const Point& corner : corners) {
        if (distance(corner, c.center) <= c.radius + EPS)
            return true;
    }

    if (isPointInSquare(c.center, s)) return true;

    Point proj;
    proj.x = std::max(s.topLeft.x, std::min(c.center.x, s.topLeft.x + s.side));
    proj.y = std::min(s.topLeft.y, std::max(c.center.y, s.topLeft.y - s.side));

    return distance(proj, c.center) <= c.radius + EPS;
}

bool isCircleInCircle(const Circle& c1, const Circle& c2) {
    return distance(c1.center, c2.center) + c1.radius <= c2.radius + EPS;
}

bool isSquareInSquare(const Square& s1, const Square& s2) {
    return s1.topLeft.x >= s2.topLeft.x - EPS &&
           s1.topLeft.y <= s2.topLeft.y + EPS &&
           s1.topLeft.x + s1.side <= s2.topLeft.x + s2.side + EPS &&
           s1.topLeft.y - s1.side >= s2.topLeft.y - s2.side - EPS;
}

bool isSquareInCircle(const Square& s, const Circle& c) {
    Point corners[4] = {
            s.topLeft,
            {s.topLeft.x + s.side, s.topLeft.y},
            {s.topLeft.x, s.topLeft.y - s.side},
            {s.topLeft.x + s.side, s.topLeft.y - s.side}
    };

    for (const Point& corner : corners) {
        if (distance(corner, c.center) > c.radius - EPS)
            return false;
    }
    return true;
}

bool isCircleInSquare(const Circle& c, const Square& s) {
    return (c.center.x - c.radius >= s.topLeft.x - EPS) &&
           (c.center.x + c.radius <= s.topLeft.x + s.side + EPS) &&
           (c.center.y + c.radius <= s.topLeft.y + EPS) &&
           (c.center.y - c.radius >= s.topLeft.y - s.side - EPS);
}