/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendoza <dmendoza@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 12:34:09 by dmendoza          #+#    #+#             */
/*   Updated: 2025/05/25 16:57:07 by dmendoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractal(t_fractal *fractal, int type)
{
	fractal->type = type;
	fractal->min_r = -2.5;
	fractal->max_r = 1.5;
	fractal->min_i = -1.5;
	fractal->max_i = 1.5;
	fractal->zoom = 1.0;
	fractal->max_iter = MAX_ITERATIONS;
	fractal->color_shift = 0;
}

void	init_julia(t_fractal *fractal, double r, double i)
{
	fractal->julia_c.r = r;
	fractal->julia_c.i = i;
}

void	init_mlx(t_fractal *fractal)
{
	fractal->mlx = mlx_init(WIDTH, HEIGHT, "FRACT-OL", false);
	if (!fractal->mlx)
		error_exit("Failed to initialize MLX");
	fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (!fractal->img)
		error_exit("Failed to create image");
}
