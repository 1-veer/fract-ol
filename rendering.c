/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub-bg <ayoub-bg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:00:55 by abougati          #+#    #+#             */
/*   Updated: 2025/03/10 19:51:18 by ayoub-bg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	pixel_put(int x, int y, t_image *image, int color)
{
	int	n;

	n = (y * image->size_line + x * (image->bits_per_pixel / 8));
	*(unsigned int *)(image->addr + n) = color;
}

void	switching_fractal(t_fract *fract, t_complex *c, t_complex *z)
{
	if (!ft_strncmp(fract->name, "mandelbrot", 10))
	{
		c->re = z->re;
		c->im = z->im;
	}
	else if (!ft_strncmp(fract->name, "julia", 5))
	{
		c->re = fract->julia_re;
		c->im = fract->julia_im;
	}
}

void	pixel_handler(int x, int y, t_fract *fract)
{
	t_complex	z;
	t_complex	c;
	int			index;
	int			my_color;

	index = 0;
	z.re = (scale(x, -2, +2, 0, W) * fract->zoom) + fract->move_x;
	z.im = (scale(y, +2, -2, 0, H) * fract->zoom) + fract->move_y;
	switching_fractal(fract, &c, &z);
	while (index < fract->iterations)
	{
		z = complex_add(complex_square(z), c);
		if ((z.re * z.re) + (z.im * z.im) > fract->hypotenuse)
		{
			my_color = scale(index, fract->black, fract->white, 0,
					fract->iterations);
			pixel_put(x, y, &fract->image, my_color);
			return ;
		}
		index++;
	}
	pixel_put(x, y, &fract->image, fract->black);
}

void	rendering(t_fract *fract)
{
	int	y;
	int	x;

	y = -1;
	while (++y < H)
	{
		x = -1;
		while (++x < W)
			pixel_handler(x, y, fract);
	}
	mlx_put_image_to_window(fract->mlx_ptr, fract->mlx_window,
		fract->image.img_ptr, 0, 0);
}
