#include <iostream>
#include <Fixed.hpp>

using std::cout;
using std::endl;

int main(void)
{
    Fixed a;
    Fixed b( a );
    Fixed c;

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    cout << endl;
    a.setRawBits(1);
    c = a;
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    cout << endl;
    a.setRawBits(123);
    b.setRawBits(456);
    c.setRawBits(789);

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    return (0);
}
