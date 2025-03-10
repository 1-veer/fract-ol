/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougati <abougati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:48:54 by abougati          #+#    #+#             */
/*   Updated: 2025/03/10 01:07:15 by abougati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/fract_ol.h"
#include <stdio.h>


//int (*f)(void *param)
int x_exit (t_fract *fract)
{
    mlx_destroy_image(fract->mlx_ptr, fract->image.img_ptr);
    mlx_destroy_window (fract->mlx_ptr, fract->mlx_window);
    mlx_destroy_display (fract->mlx_ptr);	
    free (fract->mlx_ptr);
    exit (EXIT_SUCCESS);
        return 0;
}
//int (*f)(int keycode, void *param)

int key_press (int  key, t_fract *fract)
{
    if (key == XK_Escape)
        x_exit(fract);
    else if (key == XK_w) // UP
        fract->move_y += (0.5 * fract->zoom);
    else if (key == XK_s) // DOWN
        fract->move_y -= (0.5 * fract->zoom);
    else if (key == XK_d) // RIGHT
        fract->move_x += (0.5 * fract->zoom);
    else if (key == XK_a) // LEFT
        fract->move_x -= (0.5 * fract->zoom);
    else if (key == XK_equal) 
        fract->zoom *= 0.95;
    else if (key == XK_minus)
        fract->zoom *= 1.05;
    else if (key == XK_space)
        fract->iterations += 10;
    else if (key == XK_BackSpace)
        fract->iterations -= 10;

    rendering(fract);
    return 0;
}

//int (*f)(int button, int x, int y, void *param)

int mouse_press (int button, int x, int y, t_fract *fract)
{
    (void)x;
    (void)y;
    if (button == 4)
        fract->zoom *= 0.95;
    else if (button == 5)
        fract->zoom *= 1.05;
    rendering(fract);
    return 0;
}

int motion(int x, int y, t_fract *fract)
{
   if(!ft_strncmp(fract->name, "julia", 5))
   {
       fract->julia_re = (scale(x, -2, +2, 0, W)* fract->zoom) + fract->move_x;
       fract->julia_im = (scale(y, +2, -2, 0, H)* fract->zoom) + fract->move_x;
       rendering(fract);
   }
   return 0;
}
