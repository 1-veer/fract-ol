/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougati <abougati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:15:20 by abougati          #+#    #+#             */
/*   Updated: 2025/03/09 03:29:03 by abougati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/fract_ol.h"

void initial_values(t_fract *fract)
{
	fract->iterations = 42;
	fract->hypotenuse = 4;
	
}

// void handle_events(t_fract *fract)
// {
// 	mlx_hook(fract->mlx_window, 2, 1L << 0, key_press, fract);
// 	mlx_hook(fract->mlx_window, 2, 1L << 0, key_press, fract);

	
// }

void initialize_fract(t_fract *fract)
{
		initial_values(fract);
    	fract->mlx_ptr = mlx_init();
		if (!fract->mlx_ptr)
            error_handling(fract);
		fract->mlx_window = mlx_new_window (fract->mlx_ptr, W, H, fract->name);
        if (!fract->mlx_window)
		    error_handling(fract);
		fract->image.img_ptr = mlx_new_image(fract->mlx_ptr, W, H);
		if (!fract->image.img_ptr)
			error_handling(fract);
		fract->image.addr = mlx_get_data_addr(fract->image.img_ptr, 
						&fract->image.bits_per_pixel, &fract->image.size_line, &fract->image.endian);
		//handle_events(fract);

}		
