#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::fracValue = 8;

Fixed::Fixed(void)
{
    std::cout << "Default constructor called" << std::endl;
    this->fixedValue = 0;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->setRawBits(other.getRawBits());
    return *this;
}

std::ostream &operator<<(std::ostream &out, Fixed const &other)
{
    out << other.toFloat();
    return (out);
}

Fixed::Fixed(const int _int)
{
    std::cout << "Int constructor called" << std::endl;
    this->setRawBits(_int << this->fracValue);
}

Fixed::Fixed(const float _float)
{
    std::cout << "Float constructor called" << std::endl;
    this->fixedValue = std::roundf(_float * (1 << this->fracValue));
}

int Fixed::toInt(void) const
{
    return (this->fixedValue >> this->fracValue);
}

float Fixed::toFloat(void) const
{
    return ((float)this->fixedValue / (1 << this->fracValue));
}

void Fixed::setRawBits(int const raw)
{
    this->fixedValue = raw;
}

int Fixed::getRawBits(void) const
{
    return (this->fixedValue);
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}
