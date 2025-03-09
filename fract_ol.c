/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougati <abougati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 02:05:23 by abougati          #+#    #+#             */
/*   Updated: 2025/03/09 01:55:48 by abougati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/fract_ol.h"

int	main(int ac, char *av[])
{
		t_fract fract;
		
	if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10))
		|| (ac == 4 && !ft_strncmp(av[1], "julia", 5)))
	{
		fract.name = av[1];
		initialize_fract(&fract);
		
		rendering (&fract);
		
		mlx_loop(fract.mlx_ptr);
	}
	else 
	{
		ft_putstr_fd(USAGE_MSG, 2);
		exit(EXIT_FAILURE);
	}
	
}
