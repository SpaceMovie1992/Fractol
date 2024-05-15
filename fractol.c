/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:10:30 by ahusic            #+#    #+#             */
/*   Updated: 2024/05/15 17:30:48 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(double x_move, double y_move, void *param)
{
	t_mandel	*m;
	mlx_t		*mlx;
	double		zooming;

	m = (t_mandel *)param;
	mlx = (mlx_t *)param;
	zooming = 0.1;
	x_move = 0;
	if (y_move < 0)
	{
		m->xmin -= (m->xmax - m->xmin) * zooming;
		m->xmax += (m->xmax - m->xmin) * zooming;
		m->ymin -= (m->ymax - m->ymin) * zooming;
		m->ymax += (m->ymax - m->ymin) * zooming;
	}
	else if (y_move > 0)
	{
		m->xmin += (m->xmax - m->xmin) * zooming;
		m->xmax -= (m->xmax - m->xmin) * zooming;
		m->ymin += (m->ymax - m->ymin) * zooming;
		m->ymax -= (m->ymax - m->ymin) * zooming;
	}
	m->should_draw = 1;
}

void	hook(mlx_key_data_t keydata, void *param)
{
	t_mandel	*m;

	m = (t_mandel *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		return (exit(0));
	else if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		up(m);
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		down(m);
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		right(m);
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		left(m);
	m->should_draw = 1;
}

void	initialize(t_mandel *m, char **c, mlx_t *mlx, int argc)
{
	m->should_draw = 1;
	if (argc == 2 && c[1][0] == 'm')
	{
		m->xmin = -2.5;
		m->xmax = 1.0;
		m->ymin = -1.5;
		m->ymax = 1.5;
		mlx_loop_hook(mlx, mandelbrot, m);
	}
	else if (argc == 4 && c[1][0] == 'j')
	{
		m->xmin = -1.5;
		m->xmax = 1.5;
		m->ymin = -1.5;
		m->ymax = 1.5;
		m->creal = atofract(c[2]);
		m->cimag = atofract(c[3]);
		mlx_loop_hook(mlx, julia, m);
	}
	else
	{
		write(1, "\nInvalid paramaters. Write either 'm' or 'j'.\n", 56);
		exit(0);
	}
}

int	clean_init(mlx_t *mlx, t_mandel *m)
{
	if (!(mlx))
	{
		mlx_strerror(mlx_errno);
		return (EXIT_FAILURE);
	}
	m->image = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (m->image == NULL)
	{
		mlx_close_window(mlx);
		mlx_strerror(mlx_errno);
		return (EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, m->image, 0, 0) < 0)
	{
		mlx_close_window(mlx);
		mlx_strerror(mlx_errno);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int32_t	main(int32_t argc, char *argv[])
{
	mlx_t		*mlx;
	t_mandel	*m;

	if (argc <= 1)
	{
		write(1, "\nChoose 'm' for Mandelbrot or 'j' for Julia.\n", 52);
		return (EXIT_FAILURE);
	}
	mlx = mlx_init(WIDTH, HEIGHT, "Fractal", true);
	m = (t_mandel *)malloc(sizeof(t_mandel));
	if (!mlx || !m || clean_init(mlx, m))
		return (EXIT_FAILURE);
	mlx_scroll_hook(mlx, zoom, m);
	initialize(m, argv, mlx, argc);
	mlx_key_hook(mlx, hook, m);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	free(m);
	return (EXIT_SUCCESS);
}
