/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduzant <fduzant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:18:10 by fduzant           #+#    #+#             */
/*   Updated: 2023/10/28 16:07:32 by fduzant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

float	ft_power(float base, int exponant)
{
	float	result;

	if (!exponant)
		return (1);
	if (exponant < 0)
	{
		base = 1 / base;
		exponant *= -1;
	}
	result = base;
	while(exponant > 0)
	{
		result *= base;
		exponant--;
	}
	return (result);
}

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed(const int value) : _value(value * ft_power(2, _fractional_bits))
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : _value(value * ft_power(2, _fractional_bits))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_value = fixed.getRawBits();
	return (*this);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

int		Fixed::toInt(void) const
{
	return (this->_value * ft_power(2, -_fractional_bits));
}

float	Fixed::toFloat(void) const
{
	return (this->_value * ft_power(2, -_fractional_bits));
}
//with roundf function from cmath
std::ostream	&operator<<(std::ostream &str, Fixed const &fixed_nbr)
{
	return (str << fixed_nbr.toFloat());
}
