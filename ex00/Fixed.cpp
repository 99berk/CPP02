#include "Fixed.hpp"
#include <iostream>

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
    return (*this);
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->fixedValue);
}

void Fixed::setRawBits(int const raw)
{
    this->fixedValue = raw;
}
Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}
