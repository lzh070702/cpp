#pragma once
#include <iostream>
using namespace std;

class Point {
   public:
    void setx(int x);
    int getx();
    void sety(int y);
    int gety();
    Point();                // 默认构造函数
    Point(int x, int y);    // 带参构造函数
    Point(const Point& p);  // 拷贝构造函数

   private:
    int p_x;
    int p_y;
};