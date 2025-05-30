/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendoza <dmendoza@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 19:45:12 by dmendoza          #+#    #+#             */
/*   Updated: 2025/05/30 20:16:17 by dmendoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move_fractal(t_fractal *fractal, double delta_r, double delta_i)
{
	fractal->min_r += delta_r;
	fractal->max_r += delta_r;
	fractal->min_i += delta_i;
	fractal->max_i += delta_i;
}

void	close_window(void *param)
{
	t_fractal	*fractal;

	fractal = param;
	if (fractal && fractal->mlx)
	{
		if (fractal->img)
			mlx_delete_image(fractal->mlx, fractal->img);
		mlx_close_window(fractal->mlx);
	}
}
