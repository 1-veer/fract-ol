/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub-bg <ayoub-bg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 02:05:23 by ayoub-bg          #+#    #+#             */
/*   Updated: 2025/03/06 16:33:16 by ayoub-bg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

/*
	we have 2 ways to test :
		./fractol mandelbrot
		./fractol julia r i 
*/

int	main(int ac, char *av[])
{
	if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10))
		|| (ac == 4 && !ft_strncmp(av[1], "julia", 5)))
	{
		 write(1, "working on it\n", 14);
	}
	else 
	{
		ft_putstr_fd("Usage: ./fractol mandelbrot\n", 2);
		ft_putstr_fd("Usage: ./fractol julia <Real_number> <Imaginiry_number>\n", 2);	
		exit(EXIT_FAILURE);
	}
	
}