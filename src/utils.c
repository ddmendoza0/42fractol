/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendoza <dmendoza@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 12:40:59 by dmendoza          #+#    #+#             */
/*   Updated: 2025/05/25 17:07:34 by dmendoza         ###   ########.fr       */
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
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	r = (r + color_shift) % 256;
	g = (g + color_shift) % 256;
	b = (b + color_shift) % 256;
	return ((r << 16) | (g << 8) | b);
}

void	pixel_put(t_fractal *fractal, int x, int y, int color)
{
	if (x >= 0 || x < (int)fractal->img->width || y >= 0 || y < (int)fractal->img->height )
		mlx_put_pixel(fractal->img, x, y, color);
}
