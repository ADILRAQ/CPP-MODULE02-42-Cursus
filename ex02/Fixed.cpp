/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:28:57 by araqioui          #+#    #+#             */
/*   Updated: 2023/08/17 09:03:42 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::fractionalBits = 8;
const int	Fixed::scale = (1 << Fixed::fractionalBits);

// ___Constructors && Destructors___ //

Fixed::Fixed(void) : fixedPoint(0)
{
}

Fixed::Fixed(const int nb)
{
	setRawBits(nb * getScale());
}

Fixed::Fixed(const float nb)
{
	setRawBits(roundf(nb * getScale()));
}

Fixed::Fixed(const Fixed &source)
{
	*this = source;
}

Fixed::~Fixed(void)
{
}

// ___Geters && setters___ //

float	Fixed::getScale(void) const
{
	return (scale);
}

int	Fixed::getRawBits(void) const
{
	return (fixedPoint);
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

Fixed	Fixed::operator + (const Fixed &obj)
{
	Fixed	temp;

	temp.fixedPoint = this->getRawBits() + obj.getRawBits();
	return (temp);
}

Fixed	Fixed::operator - (const Fixed &obj)
{
	Fixed	temp;

	temp.fixedPoint = this->getRawBits() - obj.getRawBits();
	return (temp);
}

Fixed	Fixed::operator * (const Fixed &obj)
{
	Fixed	temp;

	temp.fixedPoint = (this->toFloat() * obj.toFloat()) * this->scale;
	return (temp);
}

Fixed	Fixed::operator / (const Fixed &obj)
{
	Fixed	temp;

	temp.fixedPoint = (this->toFloat() / obj.toFloat()) * this->scale;
	return (temp);
}

Fixed	Fixed::operator ++ (void)
{
	++(this->fixedPoint);
	return (*this);
}

Fixed	Fixed::operator -- (void)
{
	++(this->fixedPoint);
	return (*this);
}

Fixed	Fixed::operator ++ (int)
{
	Fixed	temp(this->getRawBits() / getScale());

	++(this->fixedPoint);
	return (temp);
}

Fixed	Fixed::operator -- (int)
{
	Fixed	temp(this->getRawBits() / getScale());

	--(this->fixedPoint);
	return (temp);
}

bool	Fixed::operator > (const Fixed &obj) const
{
	return (this->getRawBits() > obj.getRawBits());
}

bool	Fixed::operator >= (const Fixed &obj) const
{
	return (this->getRawBits() >= obj.getRawBits());
}

bool	Fixed::operator < (const Fixed &obj) const
{
	return (this->getRawBits() < obj.getRawBits());
}

bool	Fixed::operator <= (const Fixed &obj) const
{
	return (this->getRawBits() <= obj.getRawBits());
}

bool	Fixed::operator == (const Fixed &obj) const
{
	return (this->getRawBits() == obj.getRawBits());
}

bool	Fixed::operator != (const Fixed &obj) const
{
	return (this->getRawBits() != obj.getRawBits());
}

// ___MIN & MAX___ //

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}
