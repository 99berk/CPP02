#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int fixedValue;
        static const int fracValue;
    public:
        Fixed(void);
        Fixed(const Fixed &other);
        Fixed &operator=(const Fixed &other);
        ~Fixed(void);
        Fixed(const int _int);
        Fixed(const float _float);

        int getRawBits(void) const;
        void setRawBits(int const raw);

        float toFloat(void) const;
        int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &other);

#endif