#pragma once
#include <iostream>
#include "point.h"
using namespace std;

class Circle {
   public:
    void seto(Point p);
    Point geto();
    void setr(int r);
    int getr();
    Circle();
    Circle(Point o, int r);
    Circle(const Circle& c);

   private:
    Point c_o;
    int c_r;
};