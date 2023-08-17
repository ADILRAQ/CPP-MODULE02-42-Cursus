/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:28:57 by araqioui          #+#    #+#             */
/*   Updated: 2023/08/14 11:22:02 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::fractionalBits = 8;
const int	Fixed::scale = (1 << Fixed::fractionalBits);

// ___Constructors && Destructors___ //

Fixed::Fixed(void) : fixedPoint(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int nb)
{
	setRawBits(nb * getScale());
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float nb)
{
	setRawBits(roundf(nb * getScale()));
	std::cout << "Float constructor called\n";
}

Fixed::Fixed(const Fixed &source)
{
	std::cout << "Copy constructor called\n";
	*this = source;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}

// ___Geters && setters___ //

int	Fixed::getRawBits(void) const
{
	return (fixedPoint);
}

float	Fixed::getScale(void) const
{
	return (scale);
}

void	Fixed::setRawBits(int const raw)
{
	this->fixedPoint = raw;
}

int	Fixed::toInt(void) const
{
	return (getRawBits() / getScale());
}

float	Fixed::toFloat(void) const
{
	return (getRawBits() / getScale());
}

// ___Overloading operators___ //

Fixed	&Fixed::operator = (const Fixed &original)
{
	std::cout << "Copy assignment operator called\n";
	if (this == &original)
		return (*this);
	this->fixedPoint = original.getRawBits();
	return (*this);
}

std::ostream	&operator << (std::ostream &output, const Fixed &obj)
{
	output << (obj.getRawBits() / obj.getScale());
	return (output);
}
