#include "Fixed.hpp"


Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed(const Fixed &from)
{
	*this =  from;
}

Fixed::Fixed(const int &intFrom)
{
	this->_value = intFrom << _bits;
}

Fixed::Fixed(const float &floatFrom)
{
	this->_value = std::roundf(floatFrom * (1 << _bits));
}

Fixed& Fixed::operator=(const Fixed &from)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &from)
		this->_value = from.getRawBits();
	return *this;
}
std::ostream & operator<<(std::ostream &output, Fixed const &fixed)
{
	//std::cout << "Stream insertion operator called" << std::endl;
	output << fixed.toFloat();
	return output;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::toInt(void) const
{
	return (this->getRawBits() >> _bits);
}

float	Fixed::toFloat(void) const {
	return ((float) this->getRawBits() / (float) (1 << _bits));
}

int		Fixed::getRawBits(void) const {
	//std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void	Fixed::setRawBits( int const raw)
{
	//std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}