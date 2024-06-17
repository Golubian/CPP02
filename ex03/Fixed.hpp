#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
	int					_value;
	const	static	int	_bits = 8;

	public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &from);
	Fixed(const int &intFrom);
	Fixed(const float &floatFrom);

	Fixed& operator=( const Fixed &from);
	bool operator>(const Fixed &from) const;
	bool operator<(const Fixed &from) const;
	bool operator>=(const Fixed &from) const;
	bool operator<=(const Fixed &from) const;
	bool operator==(const Fixed &from) const;
	bool operator!=(const Fixed &from) const;
	
	Fixed	operator+(const Fixed &from) const;
	Fixed	operator-(const Fixed &from) const;
	Fixed	operator*(const Fixed &from) const;
	Fixed	operator/(const Fixed &from) const;

	Fixed	operator++(int);
	Fixed&	operator++(void);
	Fixed	operator--(int);
	Fixed&	operator--(void);
	
	static const Fixed& min(const Fixed &a, const Fixed &b);
	static Fixed& min(Fixed &a, Fixed &b);
	static const Fixed& max(const Fixed &a, const Fixed &b);
	static Fixed& max(Fixed &a, Fixed &b);

	int		toInt(void) const;
	float	toFloat(void) const;
	int		getRawBits(void) const;
	void	setRawBits( int const raw);
};

std::ostream & operator<<(std::ostream &output, Fixed const &fixed);

#endif