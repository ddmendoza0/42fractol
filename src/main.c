/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendoza <dmendoza@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 12:14:10 by dmendoza          #+#    #+#             */
/*   Updated: 2025/05/30 18:05:10 by dmendoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_exit(char *msg)
{
	if (write(2, "Error: ", 7) < 0)
		exit(1);
	if (write(2, msg, ft_strlen(msg)) < 0)
		exit(1);
	if (write(2, "\n", 1) < 0)
		exit(1);
	exit(EXIT_FAILURE);
}

void	print_usage(void)
{
	ft_printf("Usage:\n");
	ft_printf("  ./fractol mandelbrot\n");
	ft_printf("  ./fractol julia <real> <imaginary>\n");
	ft_printf("\nExamples:\n");
	ft_printf("  ./fractol mandelbrot\n");
	ft_printf("  ./fractol julia -0.7 0.27015\n");
	ft_printf("  ./fractol julia -0.835 -0.2321\n");
	ft_printf("  ./fractol julia 0.285 0.01\n");
}

int	init_visual(t_fractal fractal)
{
	init_mlx(&fractal);
	render_fractal(&fractal);
	mlx_key_hook(fractal.mlx, key_press, &fractal);
	mlx_scroll_hook(fractal.mlx, mouse_scroll, &fractal);
	mlx_close_hook(fractal.mlx, close_window, &fractal);
	mlx_loop(fractal.mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (argc < 2)
	{
		print_usage();
		return (1);
	}
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0 && argc == 2)
	{
		init_fractal(&fractal, MANDELBROT);
	}
	else if (ft_strncmp(argv[1], "julia", 5) == 0 && argc == 4)
	{
		init_fractal(&fractal, JULIA);
		init_julia(&fractal, atof(argv[2]), atof(argv[3]));
	}
	else
	{
		print_usage();
		return (1);
	}
	init_visual(fractal);
	return (0);
}
