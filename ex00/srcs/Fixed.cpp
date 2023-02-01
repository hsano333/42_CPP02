#include "Fixed.hpp"
#include <string>
#include <iostream>

using std::cout;
using std::endl;


bit_ = 1;
int a = 1;  0000000.....       001;
Fixed f(a); 0000000.....  10000001; 
j
0000000.....       001;  Fixed:   1/ 256 = 0.004

bit_= 0 :  1
bit_= 1 :  0.5
bit_= 2 :  0.25
bit_= 3 :  0.125

Fixed::Fixed()
{
    cout << "Default constructor called" << endl;
    fixed_ = 0;
}

Fixed::Fixed(const Fixed &f)
{
    cout << "Copy constructor called" << endl;
    fixed_ = f.getRawBits();
}

void Fixed::operator=(const Fixed &f)
{
    cout << "Copy assignment operator called" << endl;
    fixed_ = f.getRawBits();
}
Fixed::~Fixed()
{
    cout << "Destructor called" << endl;
}

int Fixed::getRawBits(void) const
{
    cout << "getRawBits member function called" << endl;
    return fixed_;
}

void Fixed::setRawBits(int const raw)
{
    cout << "setRawBits member function called" << endl;
    fixed_ = raw;
}
