/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougati <abougati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:15:24 by abougati          #+#    #+#             */
/*   Updated: 2025/03/11 01:37:40 by abougati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (NULL == s || fd < 0)
		return ;
	if (*s != '\0')
	{
		write(fd, s, 1);
		ft_putstr_fd(s + 1, fd);
	}
}

void	write_msg(void)
{
	ft_putstr_fd(" Welcome to ABOUGATI's Fract'ol! \n\n"
		" You seemed to be testing it wrong.\n"
		" Try out these commands instead :\n\n"
		"	./fractol mandelbrot\n"
		"	./fractol julia <Real_number> <Imaginary_number>\n\n"
		" Wanna see some cool julia ones ? Try these:\n\n"
		"	./fractol julia -0.70176 0.3842\n"
		"	./fractol julia 0.355 0.355\n"
		"	./fractol julia -0.8 0.156\n"
		"	./fractol julia 0.285 0.01\n\n",
		2);
}

void	error_handling(t_fract *fract)
{
	if (fract && fract->mlx_ptr && fract->mlx_window)
	{
		mlx_destroy_window(fract->mlx_ptr, fract->mlx_window);
		mlx_destroy_display(fract->mlx_ptr);
		free(fract->mlx_ptr);
	}
	ft_putstr_fd("MLX_ERROR", 2);
	exit(EXIT_FAILURE);
}
