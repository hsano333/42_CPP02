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
        int overflow_;
        bool calcOverFlow(int value, int bit_p);
        bool calcOverFlow(float value, int bit_p);
        int  trans(const int value, const int bit);
        int  trans(const float value, const int bit);
    public:
        Fixed();
        Fixed(const int fixed);
        Fixed(const float fixed);
        Fixed(const Fixed &f);
        void operator=(const Fixed &f);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
        int isOverFlow(void);
};

std::ostream& operator<<(std::ostream& os, const Fixed& f);
std::ostream& operator<<(std::ostream& os, Fixed& f);
#endif
