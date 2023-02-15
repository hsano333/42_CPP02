#ifndef FIXED_H
#define FIXED_H
#include <iostream>
#include <string>
#include <sstream>

using std::string;
using std::ostream;
using std::istream;

class Fixed
{
    private:
        static const int max_bit_ = 32;
        static const int init_bit_ = 8;
        int fixed_;
        int bit_;
        bool overflow_;
        bool calcOverFlow(int value, int bit_p);
        bool calcOverFlow(float value, int bit_p);
        int  trans(const int value, const int bit);
        int  trans(const float value, const int bit);
        void change_all(int value, int bit, bool overflow);
    public:
        Fixed();
        Fixed(const int fixed);
        Fixed(const float fixed);
        Fixed(const Fixed &f);
        Fixed& operator=(const Fixed &f);
        bool operator<(const Fixed &f) const;
        bool operator<=(const Fixed &f) const;
        bool operator>(const Fixed &f) const;;
        bool operator>=(const Fixed &f) const;
        bool operator==(const Fixed &f) const;
        bool operator!=(const Fixed &f) const;
        Fixed operator+(const Fixed &f) const;
        Fixed operator-(const Fixed &f) const;
        Fixed operator*(const Fixed &f) const;
        Fixed operator/(const Fixed &f) const;
        Fixed operator++();
        Fixed operator++(int n);
        Fixed operator--();
        Fixed operator--(int n);
        static Fixed& min(Fixed& f1, Fixed& f2);
        static Fixed& max(Fixed& f1, Fixed& f2);
        static const Fixed& min(const Fixed& f1, const Fixed& f2);
        static const Fixed& max(const Fixed& f1, const Fixed& f2);
        //Fixed operator++();
        //Fixed operator--();
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
        bool isOverFlow(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& f);
std::ostream& operator<<(std::ostream& os, Fixed& f);
double ldexp(int value, int bit);
#endif
