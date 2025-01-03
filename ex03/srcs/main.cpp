#include <iostream>
#include <string>
#include "Point.hpp"
#include "Fixed.hpp"

using std::cout;
using std::endl;

int main(void)
{
    Point a = Point(-0.5f, 0);
    Point b = Point(55, 0);
    Point c = Point(0, 0.09f);
    Point point = Point(0, 0.08f);
    if (bsp(a, b, c, point))
        cout << "point is in triangle" << endl;
    else
        cout << "point is not in triangle" << endl;
    return 0;
}
