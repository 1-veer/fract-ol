/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_math.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougati <abougati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:22:34 by abougati          #+#    #+#             */
/*   Updated: 2025/03/08 16:27:41 by abougati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/fract_ol.h"

double	scale(double unscaled_num, double wanted_min,
				double wanted_max, double org_min, double org_max)
{
	return ((wanted_max - wanted_min) * (unscaled_num - org_min)
		/ (org_max - org_min) + wanted_min);
}
t_complex	complex_add(t_complex a, t_complex b)
{
	t_complex result;

	result.re = a.re + b.re;
	result.im = a.im + b.im;
	return (result);
}

t_complex	complex_square(t_complex a)
{
	t_complex result;

	result.re = a.re * a.re - a.im * a.im;
	result.im = 2 * a.re * a.im;
	return (result);
}