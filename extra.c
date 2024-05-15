/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:44:53 by ahusic            #+#    #+#             */
/*   Updated: 2024/05/15 17:32:46 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

double	atodigit(const char **str)
{
	double	res;
	int		digit;

	res = 0.0;
	while (**str >= '0' && **str <= '9')
	{
		digit = **str - '0';
		res = res * 10.0 + digit;
		(*str)++;
	}
	return (res);
}

double	atofract(const char *str)
{
	double	res;

	res = (double)ft_atoi(str);
	res /= 100;
	return (res);
}

double	atofloat(const char **str)
{
	double	res;
	double	sign;

	sign = 1.0;
	while (ft_isspace(**str))
		(*str)++;
	if (**str == '-')
	{
		sign = -1.0;
		(*str)++;
	}
	else if (**str == '+')
		(*str)++;
	res = atodigit(str);
	if (**str == '.')
	{
		str++;
		res += atofract(*str);
	}
	return (res * sign);
}
