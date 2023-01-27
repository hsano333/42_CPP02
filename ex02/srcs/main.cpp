#include <iostream>
#include "Fixed.hpp"

int main(void)
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    Fixed c = Fixed(-250.5f);
    Fixed d = Fixed(-260.2f);
    std::cout << "c:" << c << std::endl;
    std::cout << "d:" << d << std::endl;
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;


    int a1, a2, a3;
    a1 = -10 >> 1;
    a2 = -250 >> 1;
    a3 = -260 >> 1;
    std::cout << "a1=" << a1 << ", a2=" << a2 << " ,a3=" << a3<< std::endl;
    std::cout << "a1=" << a1 << ", a2=" << a2 << " ,a3=" << a3<< std::endl;
    printf("a1=%d, a2=%d, a3=%d", a1, a2, a3);
    return 0;
}
