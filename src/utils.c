/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendoza <dmendoza@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 12:40:59 by dmendoza          #+#    #+#             */
/*   Updated: 2025/06/06 18:26:46 by dmendoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double u_num, t_range range)
{
	return ((range.new_max - range.new_min) * (u_num - range.old_min) \
			/ (range.old_max - range.old_min) + range.new_min);
}

int	get_color(int iterations, int max_iter, int color_shift)
{
	int		r;
	int		g;
	int		b;
	double	t;

	if (iterations == max_iter)
		return (0x000000);
	t = (double)iterations / max_iter;
	r = (int)(255 * (9 * (1 - t) * t * t * t));
	g = (int)(255 * (15 * (1 - t) * (1 - t) * t * t));
	b = (int)(255 * (8.5 * (1 - t) * (1 - t) * (1 - t) * t));
	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	r = (r + color_shift) % 256;
	g = (g + color_shift) % 256;
	b = (b + color_shift) % 256;
	return ((r << 16) | (g << 8) | b);
}

void	pixel_put(t_fractal *fractal, int x, int y, int color)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		mlx_put_pixel(fractal->img, x, y, color);
}

void	setup_ranges(t_fractal *fractal, t_range *r_x, t_range *r_y)
{
	*r_x = (t_range){0, WIDTH, fractal->min_r, fractal->max_r};
	*r_y = (t_range){0, HEIGHT, fractal->min_i, fractal->max_i};
}
