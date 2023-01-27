#include <iostream>
#include <string>
#include "Point.hpp"
#include "Fixed.hpp"

using std::cout;
using std::endl;



float sign (Point p1, Point p2, Point p3)
{
        return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}



bool PointInTriangle (Point pt, Point v1, Point v2, Point v3)
{

    float d1, d2, d3;
    bool has_neg, has_pos;

    d1 = sign(pt, v1, v2);
    d2 = sign(pt, v2, v3);
    d3 = sign(pt, v3, v1);
    has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);
    return !(has_neg && has_pos);

}

int main(void)
{

    Point a = Point(10, 10);
    Point b = Point(-1, -10);
    Point c = Point(-10, 10);
    Point point = Point(1, 1);
    if (bsp(a, b, c, point))
        cout << "point is in circle" << endl;
    else
        cout << "point is not in circle" << endl;


    /*
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    Fixed c = Fixed(5.05f);
    Fixed d = Fixed(2);
    std::cout << "c:" << c << std::endl;
    std::cout << "d:" << d << std::endl;
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    */
    return 0;
}
