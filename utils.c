/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:37:05 by ahusic            #+#    #+#             */
/*   Updated: 2024/05/15 17:10:50 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "lib/MLX42/include/MLX42/MLX42.h"

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return ((r << 24) | (g << 16) | (b << 8) | a);
}

int	color(t_mandel *m)
{
	int		r;
	int		g;
	int		b;

	if (m->iters == MAXITERATIONS)
		return (ft_pixel(0, 0, 0, 255));
	r = (m->iters * 5) % 255;
	g = (m->iters * 10) % 255;
	b = (m->iters * 20) % 255;

	return (ft_pixel(r, g, b, 255));
}

int	ft_atoi(const char *str)
{
	int	i;
	int	s;
	int	j;

	i = 0;
	s = 1;
	j = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		j = (j * 10) + (str[i] - '0');
		i++;
	}
	return (j * s);
}
