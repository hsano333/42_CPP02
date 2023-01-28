#include <iostream>
#include <string>
#include "Point.hpp"
#include "Fixed.hpp"

using std::cout;
using std::endl;




int main(void)
{

    Point a = Point(1000.12f, 1000.23f);
    Point b = Point(-1.234f, -10.234f);
    Point c = Point(-10.098f, 10.4f);
    Point point = Point(1.3f, -100.23f);
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
