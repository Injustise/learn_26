#include <iostream>
#include "point.h"
#include "circle.h"
using namespace std;



void check(Point &a, Circle &b) {
    int ax = a.get_x(), ay = a.get_y();
    int bx = b.get_o().get_x(), by = b.get_o().get_y();
    int dis = (ax - bx) * (ax - bx) + (ay - by) * (ay - by);
    int r = b.get_r();
    if(dis < r * r) cout << "点在圆内" << endl; 
    else if(dis > r * r) cout << "点在圆外" << endl;
    else cout << "点在圆上" << endl;
}

int main() {

    Circle c;
    c.set_r(10);
    Point o;
    o.set_x(10);
    o.set_y(0);
    c.set_o(o);

    Point p;
    p.set_x(10);
    p.set_y(10);

    check(p, c);

    system("pause");

    return 0;
}