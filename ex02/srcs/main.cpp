#include <iostream>
#include "Fixed.hpp"

int main(void)
{
    Fixed a = Fixed(42.42f);
    Fixed const b = Fixed( 5.05f ) * Fixed( 2 ); 
    Fixed c = Fixed(-250.5f);
    Fixed d = Fixed(-0.2f);
    std::cout << "c:" << c << std::endl;
    std::cout << "d:" << d << std::endl;


    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << "a=" << a << ", b=" << b << " big is " << Fixed::max( a, b ) << std::endl;
    std::cout << "a=" << a << ", b=" << b << " small is " << Fixed::min( a, b ) << std::endl;
    std::cout << "a=" << a << ", b=" << b << " a+b= " << a+b << std::endl;
    std::cout << "a=" << a << ", b=" << b << " a-b= " << a-b << std::endl;
    std::cout << "a=" << a << ", b=" << b << " a*b= " << a*b << std::endl;
    std::cout << "a=" << a << ", b=" << b << " a/b= " << a/b << std::endl;
    std::cout << "a=" << a << ", b=" << b << " a > b " << ((a > b) ? "true" : "false") << std::endl;
    std::cout << "a=" << a << ", b=" << b << " a >= b " << ((a >= b) ? "true" : "false") << std::endl;
    std::cout << "a=" << a << ", b=" << b << " a < b " << ((a < b) ? "true" : "false") << std::endl;
    std::cout << "a=" << a << ", b=" << b << " a <= b " << ((a <= b) ? "true" : "false") << std::endl;
    std::cout << "a=" << a << ", b=" << b << " a == b " << ((a == b) ? "true" : "false") << std::endl;
    std::cout << "a=" << a << ", b=" << b << " a != b " << ((a != b) ? "true" : "false") << std::endl;


    int a1, a2, a3;
    a1 = -10 >> 1;
    a2 = -250 >> 1;
    a3 = -260 >> 1;
    std::cout << "a1=" << a1 << ", a2=" << a2 << " ,a3=" << a3<< std::endl;
    a1 = a1 << 2;
    a2 = a2 << 2;
    a3 = a3 << 2;
    std::cout << "a1=" << a1 << ", a2=" << a2 << " ,a3=" << a3<< std::endl;
    return 0;
}
