#include <iostream>
#include <Fixed.hpp>
#include <cmath>

int main(void)
{
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
    return 0;
}
