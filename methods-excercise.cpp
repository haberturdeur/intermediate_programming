#include <iostream>
#include <cassert>

/*
 * Doimplementujte metody struktury Rectangle
 */

struct Point {
    int x;
    int y;
};

struct Rectangle {
    Point topLeft;
    Point bottomRight;

    int width() const;
    int height() const;
    int area() const;
    bool contains(const Point& p) const;

    void move(int dx, int dy);
};

int main() {
    Rectangle r = {{0, 0}, {10, 10}};
    const Rectangle& cr = r;
    assert(cr.width() == 10);
    assert(cr.height() == 10);
    assert(cr.area() == 100);
    assert(cr.contains({5, 5}));
    assert(!cr.contains({-1, -1}));
    assert(!cr.contains({11, 11}));

    r.move(1, 1);
    assert(cr.contains({5, 5}));
    assert(!cr.contains({-1, -1}));
    assert(!cr.contains({11, 11}));

    std::cout << "All tests passed!\n";
}
