/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduzant <fduzant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:36:03 by fduzant           #+#    #+#             */
/*   Updated: 2024/01/31 12:15:27 by fduzant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &fixed);
		~Fixed();
		Fixed	&operator=(const Fixed &fixed);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
	private:
		int					_value;
		static const int	_fractional_bits = 8;
};

#endif