#ifndef FUNC_H
#define FUNC_H

#include "structs.h"

bool isPointInCircle(const Point& p, const Circle& c);
bool isPointInSquare(const Point& p, const Square& s);

bool isPointOnCircle(const Point& p, const Circle& c);
bool isPointOnSquare(const Point& p, const Square& s);

bool circlesIntersect(const Circle& c1, const Circle& c2);
bool squaresIntersect(const Square& s1, const Square& s2);
bool circleSquareIntersect(const Circle& c, const Square& s);

bool isCircleInCircle(const Circle& c1, const Circle& c2);
bool isSquareInSquare(const Square& s1, const Square& s2);
bool isSquareInCircle(const Square& s, const Circle& c);
bool isCircleInSquare(const Circle& c, const Square& s);

#endif