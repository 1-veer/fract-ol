/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougati <abougati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 02:05:46 by abougati          #+#    #+#             */
/*   Updated: 2025/03/08 16:28:21 by abougati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H
#endif

#include "mlx.h"
#include <X11/keysym.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

#include "../LIBFT/libft.h"

#define USAGE_MSG "Usage: ./fractol mandelbrot\nUsage: ./fractol julia <Real_number> <Imaginiry_number>\n"

typedef struct s_image
{
    void *img_ptr;
    char *addr;
    int bits_per_pixel;
    int size_line;
    int endian;
}                  t_image;

typedef struct s_fract
{
    char *name;
    void *mlx_ptr;
    void *mlx_window;
    t_image image;
    
}                  t_fract;

typedef struct s_complex
{
    double re;
    double im;
}                  t_complex;

//prototypes:

void    error_handling (t_fract *fract);
void initialize_fract(t_fract *fract);
void rendering (t_fract *fract);
//int  escape_X( int key , t_fract *fract);

