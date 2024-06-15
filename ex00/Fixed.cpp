#include "Fixed.hpp"


Fixed::Fixed()
{
	this->_value = 0;
}

Fixed::Fixed(const Fixed &from)
{
	this->_value = from._value;
}

Fixed& Fixed::operator=(const Fixed &from)
{
	if (this != &from)
		this->_value = from.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
}
int		Fixed::getRawBits(void) const {
	return this->_bits;
}

void	Fixed::setRawBits( int const raw)
{
	this->_value = raw;
}