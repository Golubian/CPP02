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
	Fixed(const Fixed &from);
	Fixed(const int &intFrom);
	Fixed(const float &floatFrom);
	Fixed& operator=( const Fixed &from);
	~Fixed();
	int		toInt(void) const;
	float	toFloat(void) const;
	int		getRawBits(void) const;
	void	setRawBits( int const raw);
};

std::ostream & operator<<(std::ostream &output, Fixed const &fixed);

#endif