/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:35:59 by ahusic            #+#    #+#             */
/*   Updated: 2024/05/14 13:28:08 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "lib/MLX42/include/MLX4/MLX42.h"

void	julia_calculation(float re, float im, float const_re, float const_im)
{
	double	temp;
	int		iters_count;

	iters_count = 0;
	while (iters_count < MAXITERATIONS && re * re + im * im < 4)
	{
		temp = re * re - im * im + const_re;
		im = 2 * re * im + const_im;
		re = temp;
		iters_count++;
	}
	return (iters_count);
}

void	julia(t_mandel *m)
{
	uint32_t	x;
	uint32_t	y;

	x = 0;
	y = 0;
	while (++y < m->image->height)
	{
		while (++x < m->image->width)
		{
			julia_calculation(m, x, y, m->real, m->imag);
			mlx_put_pixel(m->image, x, y, color(m));
		}
	}
}
// julia: takes a single parameter m whch is a pointer to t_mandel structure.
// Declares two variables x and y which represent the coordinates of the pixel.
// Enters a nested loop which iterates over the height of the image incrementing y on each iteration.
// Inner loop iterates over the width of the image incrementing x on each iteration.
// For each pixec it calles julia_calculation which calculates the corresponding point in the complex plane.
// Updates the iters fied of m structure with the nnumber of iters it took for the point to escape.
// Calls mlx_put_pixel that draws a pixel at (x,y) coordinates in the image with the color of the pixel determined by the color function.
// The color function calculates the color of the pixel based on the number of iterations it took for the point to escape the Julia set.
// Increments y to move to the next row of pixels.
