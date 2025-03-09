/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougati <abougati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 02:05:46 by abougati          #+#    #+#             */
/*   Updated: 2025/03/09 02:22:45 by abougati         ###   ########.fr       */
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

#define W 1000
#define H 1000

#define BLACK       0x000000  
#define WHITE       0xFFFFFF  
#define RED         0xFF0000  
#define GREEN       0x00FF00  
#define BLUE        0x0000FF  


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
    double	hypotenuse;
	int		iterations;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
    
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
double	scale(double unscaled_num, double wanted_min,
				double wanted_max, double org_min, double org_max);
t_complex	complex_add(t_complex a, t_complex b);
t_complex	complex_square(t_complex a);

