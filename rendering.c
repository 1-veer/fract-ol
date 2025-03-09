/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougati <abougati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:00:55 by abougati          #+#    #+#             */
/*   Updated: 2025/03/09 17:11:36 by abougati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/fract_ol.h"

void pixel_put (int x, int y, t_image *image, int color)
{
    int n;

    n = (y * image->size_line + x * (image->bits_per_pixel / 8));
    *(unsigned int *)(image->addr + n) = color;
}

void   pixel_handler(int x, int y, t_fract *fract)
{
    t_complex z;
    t_complex c;
    int index;
    int my_color;

    index = 0;
    z.re = 0.0;
    z.im = 0.0;
    
    c.re = (scale(x, -2, +2, 0, W) * fract->zoom) + fract->shift_x;
    c.im = (scale(y, +2, -2, 0, H) * fract->zoom) + fract->shift_y;

    while (index < fract->iterations)
    {
        z = complex_add(complex_square(z), c);    // z(1) = z(0)^2 + c
        if ((z.re * z.re) + (z.im * z.im) > fract->hypotenuse)
        {
            my_color = scale (index, BLACK, WHITE, 0, fract->iterations);
            pixel_put (x, y, &fract->image, my_color);
            return ;
        }
        index++;        
    }
    pixel_put (x, y, &fract->image, BLACK);
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