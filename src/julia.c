/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendoza <dmendoza@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 12:39:29 by dmendoza          #+#    #+#             */
/*   Updated: 2025/05/30 19:23:12 by dmendoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	draw_julia_pixel(t_fractal *fractal, int x, int y)
{
	t_complex	z;
	int			iterations;
	int			color;
	t_range		range_x;
	t_range		range_y;

	setup_ranges(fractal, &range_x, &range_y);
	z.r = map(x, range_x);
	z.i = map(y, range_y);
	iterations = julia(z, fractal->julia_c);
	color = get_color(iterations, fractal->max_iter, fractal->color_shift);
	pixel_put(fractal, x, y, color);
}

void	draw_julia(t_fractal *fractal)
{
	int			x;
	int			y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			draw_julia_pixel(fractal, x, y);
			x++;
		}
		y++;
	}
}

int	julia(t_complex z, t_complex c)
{
	int		iterations;
	double	temp;

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
