#ifndef STRUCTS_H
#define STRUCTS_H

struct Point {
    double x, y;
};

void readPoint(Point& p);
void printPoint(const Point& p);

struct Circle {
    Point center;
    double radius;
};

void readCircle(Circle& c);
void printCircle(const Circle& c);
double circlePerimeter(const Circle& c);
double circleArea(const Circle& c);

struct Square {
    Point topLeft;
    double side;
};

void readSquare(Square& s);
void printSquare(const Square& s);
double squarePerimeter(const Square& s);
double squareArea(const Square& s);

#endif
