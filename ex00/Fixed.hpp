/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:29:06 by araqioui          #+#    #+#             */
/*   Updated: 2023/08/17 09:20:36 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FIXED_HPP_
#define _FIXED_HPP_

#include <iostream>

class Fixed {
	private:
		int					fixedPoint;
		static const int	fractionalBits;

	public:
		Fixed(void);
		Fixed(const Fixed &source);
		~Fixed(void);
		Fixed	&operator = (const Fixed &original);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif /* _FIXED_HPP_ */