/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendoza <dmendoza@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 12:53:33 by dmendoza          #+#    #+#             */
/*   Updated: 2025/05/25 16:58:27 by dmendoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render_fractal(t_fractal *fractal)
{
	if (fractal->type == MANDELBROT)
		draw_mandelbrot(fractal);
	else if (fractal->type == JULIA)
		draw_julia(fractal);
	fractal->color_shift = (fractal->color_shift + 1) % 256;
	mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
}
