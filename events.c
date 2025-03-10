/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub-bg <ayoub-bg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 03:50:44 by abougati          #+#    #+#             */
/*   Updated: 2025/03/10 19:38:02 by ayoub-bg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	x_exit(t_fract *fract)
{
	mlx_destroy_image(fract->mlx_ptr, fract->image.img_ptr);
	mlx_destroy_window(fract->mlx_ptr, fract->mlx_window);
	mlx_destroy_display(fract->mlx_ptr);
	free(fract->mlx_ptr);
	exit(EXIT_SUCCESS);
	return (0);
}

int	key_press(int key, t_fract *fract)
{
	if (key == XK_Escape)
		x_exit(fract);
	else if (key == XK_w)
		fract->move_y += (0.5 * fract->zoom);
	else if (key == XK_s)
		fract->move_y -= (0.5 * fract->zoom);
	else if (key == XK_d)
		fract->move_x += (0.5 * fract->zoom);
	else if (key == XK_a)
		fract->move_x -= (0.5 * fract->zoom);
	else if (key == XK_space)
		fract->iterations += 10;
	else if (key == XK_BackSpace)
		fract->iterations -= 10;
	else if (key == XK_equal)
		fract->zoom *= 1.1;
	else if (key == XK_minus)
		fract->zoom *= 0.9;
	else if (key == XK_c)
	{
		fract->white -= 0xF00F00;
		fract->black += 0xF00F00;
	}
	rendering(fract);
	return (0);
}

int	mouse_press(int button, int x, int y, t_fract *fract)
{
	(void)x;
	(void)y;
	if (button == 4)
		fract->zoom *= 0.9;
	else if (button == 5)
		fract->zoom *= 1.1;
	rendering(fract);
	return (0);
}

int	motion(int x, int y, t_fract *fract)
{
	if (!ft_strncmp(fract->name, "julia", 5))
	{
		fract->julia_re = (scale(x, -2, +2, 0, W) * fract->zoom)
			+ fract->move_x;
		fract->julia_im = (scale(y, +2, -2, 0, H) * fract->zoom)
			+ fract->move_x;
		rendering(fract);
	}
	return (0);
}
