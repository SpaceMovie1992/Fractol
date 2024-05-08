/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:37:22 by ahusic            #+#    #+#             */
/*   Updated: 2024/05/08 18:59:42 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "lib/MLX42/include/MLX42/MLX42.h"

void	setup_mandelbrot(t_mandel *m, int pixel_x, int pixel_y)
{
	double	width_ratio;
	double	height_ratio;

	width_ratio = (double)pixel_x / m->image->width;
	height_ratio = (double)pixel_x / m->image->height;

	m->real = m->xmin + width_ratio * (m->xmax - m->xmin);
	m->imag = m->ymin + height_ratio * (m->ymax - m->ymin);

	m->creal = m->real;
	m->cimag = m->imag;
	m->iters = 0;

	m->zreal = 0.0;
	m->zimag = 0.0;
}

void	value_update(t_mandel *m)
{
	double	temp_zreal;

	temp_zreal = m->zreal;

	m->zreal = m->zreal * m->zreal - m->zimag * m->zimag + m->creal;
	m->zimag = 2 *temp_zreal * m->zimag + m->cimag;

	m->iters++;
}

void	mandelbrot(void *param)
{
	t_mandel	*m;
	uint32_t	y;
	uint32_t	x;

	m = (t_mandel *)param;
	if (m->should_draw != 1)
		return ;
	y = 0;
	while (++y < m->image->height)
	{
		x = 0;
		while (++x < m->image->width)
		{
			ft_setup_mandelbrot(m, x, y);
			while (m->iters < MAXITERATIONS && m->zreal * m->zreal + \
			m->zimag * m->zimag < 4.0)
				ft_value_update(m);
			m->color = ft_pixel(m->iters % 128, m->iters % 64, \
			m->iters % 255, 255);
			mlx_put_pixel(m->image, x, y, m->color);
		}
	}
	m->should_draw = 0;
}
