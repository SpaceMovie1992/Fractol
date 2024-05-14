/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:13:24 by ahusic            #+#    #+#             */
/*   Updated: 2024/05/08 19:22:35 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "lib/MLX42/include/MLX42/MLX42.h"

void	up(t_mandel *m)
{
	double	range;

	range = m->xmax - m->xmin;
	m->ymax -= range / 10;
	m->ymin -= range / 10;
}

void	down(t_mandel *m)
{
	double	range;

	range = m->xmax - m->xmin;
	m->ymax += range / 10;
	m->ymin += range / 10;
}

void	right(t_mandel *m)
{
	double	range;

	range = m->xmax - m->xmin;
	m->xmax += range / 10;
	m->xmin += range / 10;
}

void	left(t_mandel *m)
{
	double	range;

	range = m->xmax - m->xmin;
	m->xmax -= range / 10;
	m->xmin -= range / 10;
}
