/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendoza <dmendoza@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 12:35:44 by dmendoza          #+#    #+#             */
/*   Updated: 2025/05/25 16:13:48 by dmendoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_mandelbrot(t_fractal *fractal)
{
	int			x;
	int			y;
	t_complex	c;
	int			iterations;
	int			color;
	t_range		range_x;
	t_range		range_y;

	range_x = (t_range){0, WIDTH, fractal->min_r, fractal->max_r};
	range_y = (t_range){0, HEIGHT, fractal->min_i, fractal->max_i};
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c.r = map(x, range_x);
			c.i = map(y, range_y);
			iterations = mandelbrot(c);
			color = get_color(iterations, fractal->max_iter, fractal->color_shift);
			pixel_put(fractal, x, y, color);
			x++;
		}
		y++;
	}
}

int	mandelbrot(t_complex c)
{
	t_complex	z;
	int			iterations;
	double		temp;

	z.r = 0;
	z.i = 0;
	iterations = 0;
	while (iterations < MAX_ITERATIONS)
	{
		if ((z.r * z.r + z.i * z.i) > 4)
			break ;
		temp = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.r * z.i + c.i;
		z.r = temp;
		iterations++;
	}
	return (iterations);
}
