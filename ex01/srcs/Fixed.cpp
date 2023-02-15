#include "Fixed.hpp"
#include <string>
#include <iostream>
#include <cmath>

using std::cout;
using std::endl;
using std::ostream;
using std::istream;

double ldexp(int value, int bit)
{
    double tmp;
    tmp = value * (1 << bit);
    //cout << "my ldexp test:" << tmp << endl;
    return (double)(value * (1 << bit));
}

int Fixed::trans(const int value, const int bit)
{
    return (value << (bit));
}

int Fixed::trans(const float value, const int bit)
{
    return (roundf(ldexp(value, bit)));
}

Fixed::Fixed()
{
    cout << "Default constructor called" << endl;
    bit_ = init_bit_;
    overflow_ = false;
    fixed_ = 0;
}

Fixed::Fixed(const float fixed)
{
    cout << "Float constructor called" << endl;
    bit_ = init_bit_;
    overflow_ = calcOverFlow(fixed, bit_);
    fixed_ = trans(fixed, bit_);
}

Fixed::Fixed(const int fixed)
{
    cout << "Int constructor called" << endl;
    bit_ = init_bit_;
    overflow_ = calcOverFlow(fixed, bit_);
    fixed_ = trans(fixed, bit_);
}

Fixed::Fixed(const Fixed &f)
{
    cout << "Copy constructor called" << endl;
    bit_ = f.bit_;
    fixed_ = f.fixed_;
    overflow_ = f.overflow_;
}

Fixed& Fixed::operator=(const Fixed &f)
{
    cout << "Copy assignment operator called" << endl;
    bit_ = f.bit_;
    fixed_ = f.fixed_;
    overflow_ = f.overflow_;
    return (*this);
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

bool Fixed::calcOverFlow(float value, int bit)
{
    double tmp = ldexp(value, bit);
    if (tmp > INT_MAX)
        return (true);
    return (false);

}
bool Fixed::calcOverFlow(int value, int bit)
{
    int tmp_bit = max_bit_ - bit - 2;
    int tmp_value;
    
    tmp_value = (value >> tmp_bit);
    if (tmp_value > 0)
        return (true);
    return (false);
}

int Fixed::isOverFlow(void)
{
    return (overflow_);
}

float Fixed::toFloat(void) const
{
    return (fixed_ / ldexp(1, bit_));
}

int Fixed::toInt(void) const
{
    return ((int)(fixed_ / ldexp(1, bit_)));
}

std::ostream& operator<<(std::ostream& os, Fixed& f)
{
    os << f.toFloat();
    return (os);
}

std::ostream& operator<<(std::ostream& os, const Fixed& f)
{
    os << f.toFloat();
    return (os);
}
