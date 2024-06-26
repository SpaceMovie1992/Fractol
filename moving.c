/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:13:24 by ahusic            #+#    #+#             */
/*   Updated: 2024/05/15 17:11:17 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
