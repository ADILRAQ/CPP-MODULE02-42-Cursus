/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:29:06 by araqioui          #+#    #+#             */
/*   Updated: 2023/08/13 17:57:28 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FIXED_HPP_
#define _FIXED_HPP_

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int					fixedPoint;
		static const int	fractionalBits;
		static const int	scale;

	public:
		Fixed(void);
		Fixed(const int nb);
		Fixed(const float nb);
		Fixed(const Fixed &source);
		~Fixed(void);
		int		getRawBits(void) const;
		float	getScale(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		Fixed	&operator = (const Fixed &original);
};

std::ostream	&operator << (std::ostream &output, const Fixed &obj);

#endif /* _FIXED_HPP_ */