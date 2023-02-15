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
    return ldexp(value, bit);
}

void Fixed::change_all(int value, int bit, bool overflow)
{
    fixed_ = value;
    bit_ = bit;
    if (overflow)
        cout << "warning: overlow value" << endl;
    overflow_ = overflow;
}

Fixed::Fixed()
{
    this->change_all(0, init_bit_, false);
}

Fixed::Fixed(const float fixed)
{
    this->change_all(trans(fixed, init_bit_), init_bit_, calcOverFlow(fixed, init_bit_));
}

Fixed::Fixed(const int fixed)
{
    this->change_all(trans(fixed, init_bit_), init_bit_, calcOverFlow(fixed, init_bit_));
}

Fixed::Fixed(const Fixed &f)
{
    this->change_all(f.fixed_, f.bit_, f.overflow_);
}

Fixed& Fixed::operator=(const Fixed &f)
{
    Fixed tmp;
    this->change_all(f.fixed_, f.bit_, f.overflow_);
    return (*this);
}

Fixed::~Fixed()
{
    //cout << "Destructor called" << endl;
}

int Fixed::getRawBits(void) const
{
    //cout << "getRawBits member function called" << endl;
    return fixed_;
}

void Fixed::setRawBits(int const raw)
{
    //cout << "setRawBits member function called" << endl;
    this->change_all(raw, this->bit_, false);
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
    
    tmp_value = (value / ldexp(1, tmp_bit));
    if (tmp_value > 0)
        return (true);
    return (false);
}

bool Fixed::isOverFlow(void) const
{
    return (overflow_);
}

float Fixed::toFloat(void) const
{
    return (fixed_ / ldexp(1, bit_));
}

int Fixed::toInt(void) const
{
    return roundf((fixed_ / ldexp(1, bit_)));
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

bool Fixed::operator<(const Fixed &f) const
{
    if (this->bit_ == f.bit_)
        return (this->fixed_ < f.fixed_);
    else if (this->bit_ > f.bit_)
        return ((this->fixed_ / ldexp(1, (this->bit_ - f.bit_))) < f.fixed_);
    return (this->fixed_ < (f.fixed_ / ldexp(1, (f.bit_ - this->bit_))));
}

bool Fixed::operator<=(const Fixed &f) const
{
    if (this->bit_ == f.bit_)
        return (this->fixed_ <= f.fixed_);
    else if (this->bit_ > f.bit_)
        return ((this->fixed_ / ldexp(1, (this->bit_ - f.bit_))) <= f.fixed_);
    return (this->fixed_ <= (f.fixed_ / ldexp(1, (f.bit_ - this->bit_))));
}

bool Fixed::operator>(const Fixed &f) const
{
    if (this->bit_ == f.bit_)
        return (this->fixed_ > f.fixed_);
    else if (this->bit_ > f.bit_)
        return ((this->fixed_ / ldexp(1, (this->bit_ - f.bit_))) > f.fixed_);
    return (this->fixed_ > (f.fixed_ / ldexp(1, (f.bit_ - this->bit_))));
}

bool Fixed::operator>=(const Fixed &f) const
{
    if (this->bit_ == f.bit_)
        return (this->fixed_ >= f.fixed_);
    else if (this->bit_ > f.bit_)
        return ((this->fixed_ / ldexp(1, (this->bit_ - f.bit_))) >= f.fixed_);
    return (this->fixed_ >= (f.fixed_ / ldexp(1, (f.bit_ - this->bit_))));
}

bool Fixed::operator==(const Fixed &f) const
{
    if (this->bit_ == f.bit_)
        return (this->fixed_ == f.fixed_);
    else if (this->bit_ > f.bit_)
        return ((this->fixed_ / ldexp(1, (this->bit_ - f.bit_))) == f.fixed_);
    return (this->fixed_ == (f.fixed_ / ldexp(1, (f.bit_ - this->bit_))));
}

bool Fixed::operator!=(const Fixed &f) const
{
    if (this->bit_ == f.bit_)
        return (this->fixed_ != f.fixed_);
    else if (this->bit_ > f.bit_)
        return ((this->fixed_ / ldexp(1, (this->bit_ - f.bit_))) != f.fixed_);
    return (this->fixed_ != (f.fixed_ / ldexp(1, (f.bit_ - this->bit_))));
}

Fixed Fixed::operator+(const Fixed &f) const
{
    Fixed tmp;
    long tmpl;
    bool overflow = false;
    int bit;

    if (this->bit_ == f.bit_)
    {
        tmpl = this->fixed_ + f.fixed_; 
        bit = this->bit_;
        if (tmpl > INT_MAX || tmpl < INT_MIN || this->overflow_ || f.overflow_)
            overflow = true;
        tmp.change_all((int)tmpl, bit, overflow);
        return (tmp);
    }
    else if (this->bit_ < f.bit_)
    {
        tmpl = (this->fixed_ / ldexp(1, (f.bit_ - this->bit_))) + f.fixed_; 
        bit = f.bit_;
        if (tmpl > INT_MAX || tmpl < INT_MIN || this->overflow_ || f.overflow_)
            overflow = true;
        tmp.change_all((int)tmpl, bit, overflow);
        return (tmp);
    }
    tmpl = this->fixed_ + (f.fixed_ / ldexp(1,  (f.bit_ - this->bit_))); 
    bit = this->bit_;
    if (tmpl > INT_MAX || tmpl < INT_MIN || this->overflow_ || f.overflow_)
        overflow = true;
    tmp.change_all((int)tmpl, bit, overflow);
    return (tmp);
}

Fixed Fixed::operator-(const Fixed &f) const
{
    Fixed tmp;
    long tmpl;
    bool overflow = false;
    int bit;

    if (this->bit_ == f.bit_)
    {
        tmpl = this->fixed_ - f.fixed_; 
        bit = this->bit_;
        if (tmpl > INT_MAX || tmpl < INT_MIN || this->overflow_ || f.overflow_)
            overflow = true;
        tmp.change_all((int)tmpl, bit, overflow);
        return (tmp);
    }
    else if (this->bit_ < f.bit_)
    {
        tmpl = (this->fixed_ / ldexp(1, (f.bit_ - this->bit_))) - f.fixed_; 
        bit = f.bit_;
        if (tmpl > INT_MAX || tmpl < INT_MIN || this->overflow_ || f.overflow_)
            overflow = true;
        tmp.change_all((int)tmpl, bit, overflow);
        return (tmp);
    }
    tmpl = this->fixed_ - (f.fixed_ / ldexp(1, (f.bit_ - this->bit_))); 
    bit = this->bit_;
    if (tmpl > INT_MAX || tmpl < INT_MIN || this->overflow_ || f.overflow_)
        overflow = true;
    tmp.change_all((int)tmpl, bit, overflow);
    return (tmp);
}

Fixed Fixed::operator*(const Fixed &f) const
{
    Fixed tmp;
    long long tmpl;
    bool overflow = false;
    int bit;
    if (this->bit_ == f.bit_)
    {
        bit = this->bit_;
        tmpl = ((long long)this->fixed_ * f.fixed_) / ldexp(1, bit);
        if (tmpl > INT_MAX || tmpl < INT_MIN || this->overflow_ || f.overflow_)
        {
            cout << "overflow test:" << endl;
            cout << "overflow tmpl:" << tmpl << "this=" << this->fixed_ << ", f=" << f.fixed_  << endl;
            cout << "overflow tmpl/this:" << tmpl / this->fixed_ << endl;
            overflow = true;
        }
        tmp.change_all((int)tmpl, bit, overflow);
        return (tmp);
    }
    else if (this->bit_ < f.bit_)
    {
        tmpl = (this->fixed_ / ldexp(1, (f.bit_ - this->bit_))) * f.fixed_ / ldexp(1, f.bit_); 
        bit = f.bit_;
        if ((this->fixed_ != 0 && tmpl / this->fixed_ != f.fixed_) || this->overflow_ || f.overflow_)
            overflow = true;
        tmpl = (tmpl / ldexp(1, bit));
        tmp.change_all((int)tmpl, bit, overflow);
        return (tmp);
    }
    tmpl = this->fixed_ * (f.fixed_ / ldexp(1, (f.bit_ - this->bit_))) / ldexp(1, this->bit_); 
    bit = this->bit_;
    if ((this->fixed_ != 0 && tmpl / this->fixed_ != f.fixed_) || this->overflow_ || f.overflow_)
        overflow = true;
    tmpl = (tmpl / ldexp(1, bit));
    tmp.change_all((int)tmpl, bit, overflow);
    return (tmp);
}

Fixed Fixed::operator/(const Fixed &f) const
{
    Fixed tmp;
    long long tmpl;
    bool overflow = false;
    int bit;

    if (f.fixed_ == 0)
    {
        cout << "warning: " << endl;
        tmp.change_all(0, init_bit_, true);
        return (tmp);
    }

    if (this->bit_ == f.bit_)
    {
        tmpl = (this->fixed_ << this->bit_) / f.fixed_;
        bit = this->bit_;
        if (tmpl > INT_MAX || this->overflow_ || f.overflow_)
            overflow = true;
        tmp.change_all((int)tmpl, bit, overflow);
        return (tmp);
    }
    else if (this->bit_ < f.bit_)
    {
        tmpl = (this->fixed_ / ldexp(1, (f.bit_ - this->bit_ + this->bit_))) / f.fixed_ * ldexp(1, f.bit_); 
        bit = f.bit_;
        if (tmpl > INT_MAX || this->overflow_ || f.overflow_)
            overflow = true;
        tmp.change_all((int)tmpl, bit, overflow);
        return (tmp);
    }
    tmpl = (this->fixed_ / ldexp(1, this->bit_)) / (f.fixed_ / ldexp(1, (f.bit_ - this->bit_))) * ldexp(1, this->bit_); 
    bit = this->bit_;
    if (tmpl > INT_MAX || this->overflow_ || f.overflow_)
        overflow = true;
    tmp.change_all((int)tmpl, bit, overflow);
    return (tmp);
}

Fixed Fixed::operator++(void)
{
    bool overflow = this->overflow_;
    long tmpl;

    if (this->fixed_ == INT_MAX)
        overflow = true;
    tmpl = this->fixed_ + 1;
    this->change_all(tmpl, this->bit_, overflow);
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed tmp = Fixed(*this);
    bool overflow = this->overflow_;
    long tmpl;

    if (this->fixed_ == INT_MAX)
        overflow = true;
    tmpl = this->fixed_ + 1;
    this->change_all(tmpl, this->bit_, overflow);
    return (tmp);
}

Fixed Fixed::operator--(void)
{
    bool overflow = this->overflow_;
    long tmpl;

    if (this->fixed_ == INT_MIN)
        overflow = true;
    tmpl = this->fixed_ - 1;
    this->change_all(tmpl, this->bit_, overflow);
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp = Fixed(*this);
    bool overflow = this->overflow_;
    long tmpl;

    if (this->fixed_ == INT_MIN)
        overflow = true;
    tmpl = this->fixed_ - 1;
    this->change_all(tmpl, this->bit_, overflow);
    return (tmp);
}

Fixed& Fixed::min(Fixed& f1, Fixed& f2)
{
    if (f1 >= f2)
        return (f2);
    return (f1);
}

Fixed& Fixed::max(Fixed& f1, Fixed& f2)
{
    if (f1 >= f2)
        return (f1);
    return (f2);
}

const Fixed& Fixed::min(const Fixed& f1, const Fixed& f2)
{
    if (f1 >= f2)
        return (f2);
    return (f1);
}

const Fixed& Fixed::max(const Fixed& f1, const Fixed& f2)
{
    if (f1 >= f2)
        return (f1);
    return (f2);
}
