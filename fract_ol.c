/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougati <abougati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 02:05:23 by ayoub-bg          #+#    #+#             */
/*   Updated: 2025/03/07 22:30:02 by abougati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/fract_ol.h"

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
		void *connection;
		void *window;

		connection = mlx_init();
		if (!connection)
		{
			ft_putstr_fd("Connection error\n", 2);
			return 1;
		}
		
		window = mlx_new_window (connection , 2000 , 1200 , "TEST");

		if (!window)
		{
			mlx_destroy_display (connection);	
			free (connection);
			ft_putstr_fd("window error\n", 2);
			return 1;
		}
		
		mlx_loop(connection);
		// write(1, "working on it\n", 14);
	}
	else 
	{
		ft_putstr_fd("Usage: ./fractol mandelbrot\n", 2);
		ft_putstr_fd("Usage: ./fractol julia <Real_number> <Imaginiry_number>\n", 2);	
		exit(EXIT_FAILURE);
	}
	
}
