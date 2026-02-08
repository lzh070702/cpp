#include "point.h"

void Point::setx(int x) {
    p_x = x;
}
int Point::getx() {
    return p_x;
}
void Point::sety(int y) {
    p_y = y;
}
int Point::gety() {
    return p_y;
}
Point::Point() {}
Point::Point(int x, int y) : p_x(x), p_y(y) {}
Point::Point(const Point& p) : Point(p.p_x, p.p_y) {}