#include "Fixed.hpp"


Fixed::Fixed()
{
	this->_value = 0;
}

Fixed::~Fixed()
{
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
	if (this != &from)
		this->_value = from.getRawBits();
	return *this;
}

bool Fixed::operator==(const Fixed &from) const
{
	return (this->getRawBits() == from.getRawBits());
}

bool Fixed::operator!=(const Fixed &from) const
{
	return (this->getRawBits() != from.getRawBits());
}

bool Fixed::operator>(const Fixed &from) const
{
	return (this->getRawBits() > from.getRawBits());
}

bool Fixed::operator>=(const Fixed &from) const
{
	return (this->getRawBits() >= from.getRawBits());
}

bool Fixed::operator<(const Fixed &from) const
{
	return (this->getRawBits() < from.getRawBits());
}

bool Fixed::operator<=(const Fixed &from) const
{
	return (this->getRawBits() <= from.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &from) const
{
	return Fixed(this->toFloat() + from.toFloat());
}

Fixed	Fixed::operator-(const Fixed &from) const
{
	return Fixed(this->toFloat() - from.toFloat());
}

Fixed	Fixed::operator*(const Fixed &from) const
{
	return Fixed(this->toFloat() * from.toFloat());
}

Fixed	Fixed::operator/(const Fixed &from) const
{
	return Fixed(this->toFloat() / from.toFloat());
}

Fixed&	Fixed::operator++(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed copy(*this);
	copy._value = this->getRawBits() + 1;
	return (copy);
}

Fixed&	Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed copy(*this);
	copy._value = this->getRawBits() - 1;
	return (copy);
}

std::ostream & operator<<(std::ostream &output, Fixed const &fixed)
{
	output << fixed.toFloat();
	return output;
}

Fixed& Fixed::min( Fixed &a, Fixed &b ) {
    return (a.getRawBits() < b.getRawBits() ? a : b);
}

const Fixed& Fixed::min( const Fixed &a, const Fixed &b ) {
    return (a.getRawBits() < b.getRawBits() ? a : b);
}

Fixed& Fixed::max( Fixed &a, Fixed &b ) {
    return (a.getRawBits() > b.getRawBits() ? a : b);
}

const Fixed& Fixed::max( const Fixed &a, const Fixed &b ) {
    return (a.getRawBits() > b.getRawBits() ? a : b);
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