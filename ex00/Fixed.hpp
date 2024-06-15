#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	private:
	int					_value;
	const	static	int	_bits = 8;

	public:
	Fixed();
	Fixed(const Fixed &from);
	Fixed& operator=( const Fixed &from);
	~Fixed();
	int		getRawBits(void) const;
	void	setRawBits( int const raw);
};

#endif