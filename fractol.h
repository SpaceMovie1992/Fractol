/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:26:18 by ahusic            #+#    #+#             */
/*   Updated: 2024/05/14 13:27:26 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <errno.h>
# include "lib/MLX42/include/MLX42/MLX42.h"

# define WIDTH 1200
# define HEIGHT 1080
# define MAXITERATIONS 1000

typedef struct Mandelparams
{
	double		xmin;
	double		xmax;
	double		ymin;
	double		ymax;
	double		real;
	double		imag;
	double		creal;
	double		cimag;
	double		zreal;
	double		zimag;
	double		temp_zreal;
	int			iters;
	mlx_image_t	*image;
	mlx_t		*mlx;
	uint32_t	color;
	int			should_draw;
}				t_mandel;

// pixels ad colors
int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
int		color(t_mandel *m);

// mandelbrot
void	setup_mandelbrot(t_mandel *m, int pixel_x, int pixel_y);
void	mandelbrot(t_mandel *m);

// julia
void	julia_calculation(float re, float im, float const_re, float const_im);
void	julia(t_mandel *m);

// moving
void	up(t_mandel *m);
void	down(t_mandel *m);
void	right(t_mandel *m);
void	left(t_mandel *m);

// hooks
void	hook(mlx_key_data_t keydata, void *param);
void	initialize(t_mandel *m, char **c, mlx_t *mlx, int argc);
int		clean_init(mlx_t *mlx, t_mandel *m);

#endif
