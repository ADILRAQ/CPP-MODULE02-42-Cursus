/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:29:06 by araqioui          #+#    #+#             */
/*   Updated: 2023/08/17 09:03:39 by araqioui         ###   ########.fr       */
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
		int					getRawBits(void) const;
		float				getScale(void) const;
		void				setRawBits(int const raw);
		float				toFloat(void) const;
		int					toInt(void) const;
		Fixed				&operator = (const Fixed &original);
		Fixed				operator + (const Fixed &obj);
		Fixed				operator - (const Fixed &obj);
		Fixed				operator * (const Fixed &obj);
		Fixed				operator / (const Fixed &obj);
		Fixed				operator ++ (void);
		Fixed				operator ++ (int);
		Fixed				operator -- (void);
		Fixed				operator -- (int);
		bool				operator > (const Fixed &obj) const;
		bool				operator >= (const Fixed &obj) const;
		bool				operator < (const Fixed &obj) const;
		bool				operator <= (const Fixed &obj) const;
		bool				operator == (const Fixed &obj) const;
		bool				operator != (const Fixed &obj) const;
		static Fixed		&min(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);
};

std::ostream	&operator << (std::ostream &output, const Fixed &obj);

#endif /* _FIXED_HPP_ */