/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_math.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougati <abougati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:22:34 by abougati          #+#    #+#             */
/*   Updated: 2025/03/11 01:05:31 by abougati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

double	scale(double unscaled_num, double wanted_min, double wanted_max,
		double org_max)
{
	return ((wanted_max - wanted_min) * unscaled_num / org_max + wanted_min);
}

t_complex	complex_add(t_complex a, t_complex b)
{
	t_complex	result;

	result.re = a.re + b.re;
	result.im = a.im + b.im;
	return (result);
}

t_complex	complex_square(t_complex a)
{
	t_complex	result;

	result.re = (a.re * a.re) - (a.im * a.im);
	result.im = 2 * a.re * a.im;
	return (result);
}

double	adapt_inpt(char *str)
{
	int		a;
	double	b;
	int		sign;
	double	x;

	a = 0;
	b = 0.0;
	sign = 1;
	x = 1.0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign *= -1;
	while (*str && *str != '.')
		a = (a * 10) + (*str++ - '0');
	if (*str == '.')
		str++;
	while (*str)
	{
		x /= 10;
		b += (*str++ - '0') * x;
	}
	return ((a + b) * sign);
}
