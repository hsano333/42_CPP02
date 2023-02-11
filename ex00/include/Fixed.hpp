#ifndef FIXED_H
#define FIXED_H
#include <iostream>
#include <string>

class Fixed
{
    private:
        int fixed_;
        static const int bit_ = 8;
    public:
        Fixed();
        Fixed(const Fixed &f);
        Fixed& operator=(const Fixed &f);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif
