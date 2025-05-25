/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendoza <dmendoza@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 12:51:46 by dmendoza          #+#    #+#             */
/*   Updated: 2025/05/25 17:39:43 by dmendoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_press(mlx_key_data_t key, void *param)
{
	t_fractal	*fractal;

	fractal = param;
	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
		close_window(fractal);
}

void	zoom_fractal(void *param, int x, int y, double zoom_factor)
{
	double		mouse_r;
	double		mouse_i;
	double		width;
	double		height;
	t_fractal	*fractal;
	t_range		range_x;
	t_range		range_y;

	fractal = param;
	range_x = (t_range){0, WIDTH, fractal->min_r, fractal->max_r};
	range_y = (t_range){0, HEIGHT, fractal->min_i, fractal->max_i};
	mouse_r = map(x, range_x);
	mouse_i = map(y, range_y);
	width = fractal->max_r - fractal->min_r;
	height = fractal->max_i - fractal->min_i;
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

void	close_window(void *param)
{
	t_fractal	*fractal;

	fractal = param;
	mlx_delete_image(fractal->mlx, fractal->img);
	mlx_terminate(fractal->mlx);
	exit(0);
}
