#include "Fixed.hpp"
#include <cmath>

const int Fixed::fracValue = 8;

Fixed::Fixed(void)
{
    this->fixedValue = 0;
}

Fixed::Fixed(const Fixed &other)
{
    *this = other;
}

Fixed::Fixed(const int _int)
{
    this->setRawBits(_int << this->fracValue);
}

Fixed::Fixed(const float _float)
{
    this->setRawBits(std::roundf(_float * (1 << this->fracValue)));
}

int Fixed::toInt(void) const
{
    return (this->fixedValue >> this->fracValue);
}

float Fixed::toFloat(void) const
{
    return ((float)(this->fixedValue) / (1 << this->fracValue));
}

int Fixed::getRawBits(void) const
{
    return (this->fixedValue);
}

void Fixed::setRawBits(int const raw)
{
    this->fixedValue = raw;
}

std::ostream &operator<<(std::ostream &out, Fixed const &other)
{
    out << other.toFloat();
    return (out);
}

bool Fixed::operator==(const Fixed &other)
{
    if (this->getRawBits() == other.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator!=(const Fixed &other)
{
    if (this->getRawBits() != other.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator>=(const Fixed &other)
{
    if (this->getRawBits() >= other.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator<=(const Fixed &other)
{
    if (this->getRawBits() <= other.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator>(const Fixed &other)
{
    if (this->getRawBits() > other.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator<(const Fixed &other)
{
    if (this->getRawBits() < other.getRawBits())
        return (true);
    return (false);
}

float Fixed::operator*(const Fixed &other)
{
    return (this->toFloat() * other.toFloat());
}

float Fixed::operator/(const Fixed &other)
{
    return (this->toFloat() / other.toFloat());
}


float Fixed::operator+(const Fixed &other)
{
    return (this->toFloat() + other.toFloat());
}

float Fixed::operator-(const Fixed &other)
{
    return (this->toFloat() - other.toFloat());
}

Fixed Fixed::operator++(int)
{
    Fixed   tmp(*this);
    tmp.fixedValue = this->fixedValue++;
    return (tmp);
}

Fixed &Fixed::operator++(void)
{
    ++this->fixedValue;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed   tmp(*this);
    tmp.fixedValue = this->fixedValue--;
    return (tmp);
}

Fixed &Fixed::operator--(void)
{
    --this->fixedValue;
    return (*this);
}

Fixed &Fixed::max(Fixed &obj_1, Fixed &obj_2)
{
    return (obj_1.toFloat() < obj_2.toFloat()) ? obj_1 : obj_2;
}

Fixed &Fixed::min(Fixed &obj_1, Fixed &obj_2)
{
    return (obj_1.toFloat() < obj_2.toFloat()) ? obj_1 : obj_2;
}

const Fixed &Fixed::max(const Fixed &obj_1, const Fixed &obj_2)
{
    return (obj_1.toFloat() > obj_2.toFloat()) ? obj_1 : obj_2;
}

const Fixed &Fixed::min(const Fixed &obj_1, const Fixed &obj_2)
{
    return (obj_1.toFloat() < obj_2.toFloat()) ? obj_1 : obj_2;
}

Fixed::~Fixed(void)
{

}
