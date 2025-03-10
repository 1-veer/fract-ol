/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougati <abougati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 02:05:46 by abougati          #+#    #+#             */
/*   Updated: 2025/03/10 04:31:23 by abougati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

# define W 600
# define H 600

# define BLACK 0x000000  
# define WHITE 0xFFFFFF  
# define RED 0xFF0000  
# define GREEN 0x00FF00  
# define BLUE 0x0000FF  

typedef struct s_image
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}				t_image;

typedef struct s_fract
{
	char	*name;
	void	*mlx_ptr;
	void	*mlx_window;
	t_image	image;
	double	hypotenuse;
	int		iterations;
	int		white;
	int		black;
	double	move_x;
	double	move_y;
	double	zoom;
	double	julia_re;
	double	julia_im;
}				t_fract;

typedef struct s_complex
{
	double	re;
	double	im;
}				t_complex;

void		error_handling(t_fract *fract);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_putstr_fd(char *s, int fd);
void		write_msg(void);
void		initialize_fract(t_fract *fract);
void		rendering(t_fract *fract);

double		scale(double unscaled_num, double wanted_min,
				double wanted_max, double org_min,
				double org_max);

t_complex	complex_add(t_complex a, t_complex b);
t_complex	complex_square(t_complex a);
double		adapt_inpt(char *str);

int			key_press(int key, t_fract *fract);
int			x_exit(t_fract *fract);
int			mouse_press(int button, int x, int y, t_fract *fract);
int			motion(int x, int y, t_fract *fract);

#endif
