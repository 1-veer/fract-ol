/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougati <abougati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 02:05:23 by abougati          #+#    #+#             */
/*   Updated: 2025/03/10 00:41:23 by abougati         ###   ########.fr       */
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
		if (av[2] && av[3])
		{
			fract.julia_re = adapt_inpt(av[2]);
			fract.julia_im = adapt_inpt(av[3]);
		}
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
