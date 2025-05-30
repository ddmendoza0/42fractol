/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendoza <dmendoza@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 12:51:46 by dmendoza          #+#    #+#             */
/*   Updated: 2025/05/30 19:52:47 by dmendoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	handler(t_fractal *fractal, int option)
{
	if (option == 1)
	{
		fractal->color_shift = (fractal->color_shift + 10) % 256;
		render_fractal(fractal);
	}
	else if (option == 2)
	{
		init_fractal(fractal, fractal->type);
		render_fractal(fractal);
	}
}

static void	handle_movement(t_fractal *fractal, mlx_key_data_t key, \
		double move_speed)
{
	if (key.key == MLX_KEY_LEFT)
	{
		move_fractal(fractal, -move_speed, 0);
		render_fractal(fractal);
	}
	else if (key.key == MLX_KEY_RIGHT)
	{
		move_fractal(fractal, move_speed, 0);
		render_fractal(fractal);
	}
	else if (key.key == MLX_KEY_UP)
	{
		move_fractal(fractal, 0, -move_speed);
		render_fractal(fractal);
	}
	else if (key.key == MLX_KEY_DOWN)
	{
		move_fractal(fractal, 0, move_speed);
		render_fractal(fractal);
	}
}

void	key_press(mlx_key_data_t key, void *param)
{
	t_fractal	*fractal;
	double		move_speed;

	fractal = param;
	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
		close_window(fractal);
	if (key.action == MLX_PRESS || key.action == MLX_REPEAT)
	{
		move_speed = (fractal->max_r - fractal->min_r) * 0.1;
		if (key.key == MLX_KEY_C)
			handler(fractal, 1);
		else if (key.key == MLX_KEY_R)
			handler(fractal, 2);
		else
			handle_movement(fractal, key, move_speed);
	}
}

void	zoom_fractal(void *param, int x, int y, double zoom_factor)
{
	double		mouse_r;
	double		mouse_i;
	t_fractal	*fractal;
	t_range		range_x;
	t_range		range_y;

	fractal = param;
	range_x = (t_range){0, WIDTH, fractal->min_r, fractal->max_r};
	range_y = (t_range){0, HEIGHT, fractal->min_i, fractal->max_i};
	mouse_r = map(x, range_x);
	mouse_i = map(y, range_y);
	fractal->min_r = mouse_r - (mouse_r - fractal->min_r) * zoom_factor;
	fractal->max_r = mouse_r + (fractal->max_r - mouse_r) * zoom_factor;
	fractal->min_i = mouse_i - (mouse_i - fractal->min_i) * zoom_factor;
	fractal->max_i = mouse_i + (fractal->max_i - mouse_i) * zoom_factor;
}

void	mouse_scroll(double xdelta, double ydelta, void *param)
{
	t_fractal	*fractal;
	int			x;
	int			y;

	fractal = param;
	(void)xdelta;
	mlx_get_mouse_pos(fractal->mlx, &x, &y);
	if (ydelta > 0)
	{
		zoom_fractal(fractal, x, y, 0.9);
		render_fractal(fractal);
	}
	else if (ydelta < 0)
	{
		zoom_fractal(fractal, x, y, 1.1);
		render_fractal(fractal);
	}
}
