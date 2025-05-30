/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendoza <dmendoza@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 12:19:42 by dmendoza          #+#    #+#             */
/*   Updated: 2025/05/30 20:29:39 by dmendoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "MLX42/MLX42.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define WIDTH 800
# define HEIGHT 600
# define MAX_ITERATIONS 100

# define MANDELBROT 1
# define JULIA 2

typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

typedef struct s_range
{
	double	old_min;
	double	old_max;
	double	new_min;
	double	new_max;
}	t_range;

typedef struct s_fractal
{
	void		*mlx;
	mlx_image_t	*img;
	int			type;
	double		min_r;
	double		max_r;
	double		min_i;
	double		max_i;
	double		zoom;
	t_complex	julia_c;
	int			max_iter;
	int			color_shift;
}	t_fractal;

/* main.c */
int		main(int argc, char **argv);
void	error_exit(char *msg);
//void	print_usage(void);

/* init.c */
void	init_fractal(t_fractal *fractal, int type);
void	init_mlx(t_fractal *fractal);
void	init_julia(t_fractal *fractal, double r, double i);

/* mandelbrot.c */
int		mandelbrot(t_complex c);
void	draw_mandelbrot(t_fractal *fractal);

/* julia.c */
int		julia(t_complex z, t_complex c);
void	draw_julia(t_fractal *fractal);

/* utils.c */
double	map(double u_num, t_range range);
int		get_color(int iterations, int max_iter, int color_shift);
void	pixel_put(t_fractal *fractal, int x, int y, int color);
void	setup_ranges(t_fractal *fractal, t_range *r_x, t_range *r_y);

/* events.c */
void	key_press(mlx_key_data_t key, void *param);
void	mouse_scroll(double xdelta, double ydelta, void *param);

/* actions.c */
void	move_fractal(t_fractal *fractal, double delta_r, double delta_i);
void	close_window(void *param);

/* render.c */
void	render_fractal(t_fractal *fractal);

#endif
