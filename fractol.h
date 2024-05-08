/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:26:18 by ahusic            #+#    #+#             */
/*   Updated: 2024/05/02 18:47:23 by ahusic           ###   ########.fr       */
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

# define WIDTH 1000
# define HEIGHT 1000
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

// void	setup_mandelbrot(t_mandel *m, int pixel_x, int pixel_y);
#endif
