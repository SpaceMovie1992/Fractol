/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:35:59 by ahusic            #+#    #+#             */
/*   Updated: 2024/05/15 17:27:27 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_calculation(float re, float im, float const_re, float const_im)
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

void	julia(void *param)
{
	uint32_t	x;
	uint32_t	y;
	t_mandel	*m;
	double		aspect_ratio;

	m = (t_mandel *)param;
	if (m->should_draw != 1)
		return ;
	aspect_ratio = (double)m->image->width / m->image->height;
	y = 0;
	while (++y < m->image->height)
	{
		x = 0;
		while (++x < m->image->width)
		{
			m->real = m->xmin + (double)x / m->image->width \
			* (m->xmax - m->xmin) * aspect_ratio;
			m->imag = m->ymin + (double)y / m->image->height \
			* (m->ymax - m->ymin);
			m->iters = julia_calculation(m->real, m->imag, m->creal, m->cimag);
			mlx_put_pixel(m->image, x, y, color(m));
		}
	}
}
