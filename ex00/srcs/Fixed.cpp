#include "Fixed.hpp"
#include <string>
#include <iostream>

using std::cout;
using std::endl;


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
    fixed_ = raw;
}