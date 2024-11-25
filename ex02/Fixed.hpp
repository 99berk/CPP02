#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
    private:
        int fixedValue;
        static const int fracValue;

    public:
        Fixed(void);
        Fixed(const Fixed &other);
        Fixed(const int _int);
        Fixed(const float _float);
        ~Fixed(void);

        bool operator>(const Fixed &other);
        bool operator<(const Fixed &other);
        bool operator>=(const Fixed &other);
        bool operator<=(const Fixed &other);
        bool operator==(const Fixed &other);
        bool operator!=(const Fixed &other);

        float operator*(const Fixed &other);
        float operator/(const Fixed &other);
        float operator+(const Fixed &other);
        float operator-(const Fixed &other);

        Fixed &operator++();
        Fixed operator++(int);
        Fixed &operator--();
        Fixed operator--(int);

        static Fixed &min(Fixed &a, Fixed &b);
        static const Fixed &min(const Fixed &a, const Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);

        float toFloat(void) const;
        int toInt(void) const;

        int getRawBits(void) const;
        void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &out, const Fixed &other);

#endif