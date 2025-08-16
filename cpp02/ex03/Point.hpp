#pragma once
#include "Fixed.hpp"

class Point
{
private:
    Fixed const x;
    Fixed const y;

public:
    Point();
    Point(const float x, const float y);
    Point(const Point &other);
    Point &operator=(const Point &other);
    ~Point();

    Fixed const &getX() const;
    Fixed const &getY() const;
};
bool bsp(Point const a, Point const b, Point const c, Point const point);