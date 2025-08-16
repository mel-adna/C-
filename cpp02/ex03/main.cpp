#include "Point.hpp"

static void test(Point const &a, Point const &b, Point const &c, Point const &p) {
    std::cout << "Point (" << p.getX() << ", " << p.getY() << ") is "
              << (bsp(a, b, c, p) ? "inside" : "outside")
              << " the triangle.\n";
}

int main() {
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(0.0f, 10.0f);

    test(a, b, c, Point(1.0f, 1.0f));   // inside
    test(a, b, c, Point(5.0f, 0.0f));   // on edge -> outside
    test(a, b, c, Point(0.0f, 0.0f));   // vertex  -> outside
    test(a, b, c, Point(3.0f, 7.0f));   // outside

    return 0;
}
