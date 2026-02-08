#include <iostream>
#include "circle.h"
#include "point.h"
using namespace std;

void printPointCircleRelation(Circle& c, Point& p) {
    int len = (p.getx() - c.geto().getx()) * (p.getx() - c.geto().getx()) +
              (p.gety() - c.geto().gety()) * (p.gety() - c.geto().gety());
    cout << "点(" << p.getx() << "," << p.gety() << ")在圆";

    if (len > c.getr() * c.getr()) {
        cout << "外" << endl;
    }
    if (len == c.getr() * c.getr()) {
        cout << "上" << endl;
    }
    if (len < c.getr() * c.getr()) {
        cout << "内" << endl;
    }
}

int main() {
    Point o;
    o.setx(0);
    o.sety(0);
    Circle c;
    c.seto(o);
    c.setr(10);
    Point a;  // 默认构造函数
    a.setx(0);
    a.sety(9);
    Point b(0, 10);  // 带参构造函数
    Point d(b);      // 拷贝构造函数
    d.sety(11);
    printPointCircleRelation(c, a);
    printPointCircleRelation(c, b);
    printPointCircleRelation(c, d);
    return 0;
}