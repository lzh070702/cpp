#include "circle.h"

void Circle::seto(Point p) {
    c_o = p;
}
Point Circle::geto() {
    return c_o;
}
void Circle::setr(int r) {
    c_r = r;
}
int Circle::getr() {
    return c_r;
}
Circle::Circle() {}
Circle::Circle(Point o, int r) : c_o(o), c_r(r) {}
Circle::Circle(const Circle& c) : Circle(c.c_o, c.c_r) {}