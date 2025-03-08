/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougati <abougati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:15:24 by abougati          #+#    #+#             */
/*   Updated: 2025/03/08 14:59:51 by abougati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/fract_ol.h"

void    error_handling (t_fract *fract)
{
	if (fract || fract->mlx_ptr || fract->mlx_window)
	{
		mlx_destroy_window (fract->mlx_ptr, fract->mlx_window);
		mlx_destroy_display (fract->mlx_ptr);	
		free (fract->mlx_ptr);
	}
	perror ("MLX_ERROR");
	exit (EXIT_FAILURE);
}