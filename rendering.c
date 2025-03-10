/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougati <abougati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:00:55 by abougati          #+#    #+#             */
/*   Updated: 2025/03/10 00:52:29 by abougati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/fract_ol.h"

void pixel_put (int x, int y, t_image *image, int color)
{
    int n;

    n = (y * image->size_line + x * (image->bits_per_pixel / 8));
    *(unsigned int *)(image->addr + n) = color;
}

void switching_farctal(t_fract *fract, t_complex *c, t_complex *z)
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

void   pixel_handler(int x, int y, t_fract *fract)
{
    t_complex z;
    t_complex c;
    int index;
    int my_color;

    index = 0;
    z.re = (scale(x, -2, +2, 0, W) * fract->zoom) + fract->move_x;
    z.im = (scale(y, +2, -2, 0, H) * fract->zoom) + fract->move_y;
    
    switching_farctal(fract, &c , &z);
    while (index < fract->iterations)
    {
        z = complex_add(complex_square(z), c);    // z(1) = z(0)^2 + c
        if ((z.re * z.re) + (z.im * z.im) > fract->hypotenuse)
        {
            my_color = scale(index, 0x000000, 0xFF00FF, 0, fract->iterations); // Changed color scale to black to magenta
            pixel_put(x, y, &fract->image, my_color);
            return;
        }
        index++;        
    }
    pixel_put(x, y, &fract->image, 0x000000); // Changed color to black
}

 void rendering (t_fract *fract)
{
    int y;
    int x;
    
    y = 0;
    while (y++ < H)
        {
            x = 0;
            while (x++ < W)
                pixel_handler(x, y, fract);
        }
    mlx_put_image_to_window(fract->mlx_ptr, fract->mlx_window, fract->image.img_ptr, 0, 0);    
    
}