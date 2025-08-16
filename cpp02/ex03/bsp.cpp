#include "Point.hpp"

static Fixed sign(Point const &p1, Point const &p2, Point const &p3) {
    Fixed x1 = p1.getX();
    Fixed y1 = p1.getY();
    Fixed x2 = p2.getX();
    Fixed y2 = p2.getY();
    Fixed x3 = p3.getX();
    Fixed y3 = p3.getY();

    // cross product of (p1 - p3) and (p2 - p3)
    return (x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed s1 = sign(point, a, b);
    Fixed s2 = sign(point, b, c);
    Fixed s3 = sign(point, c, a);

    // If on any edge (exactly colinear), return false as per subject.
    if (s1 == Fixed(0) || s2 == Fixed(0) || s3 == Fixed(0))
        return false;

    bool hasNeg = (s1 < Fixed(0)) || (s2 < Fixed(0)) || (s3 < Fixed(0));
    bool hasPos = (s1 > Fixed(0)) || (s2 > Fixed(0)) || (s3 > Fixed(0));

    // strictly inside if NOT mixed signs (i.e., all positive or all negative)
    return !(hasNeg && hasPos);
}
