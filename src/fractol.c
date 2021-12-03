/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 21:33:12 by rkenji-s          #+#    #+#             */
/*   Updated: 2021/12/02 19:13:45 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	my_fractal(t_data *mlx)
{
	if (mlx->fractal == 'm')
		my_mandelbrot(mlx);
	if (mlx->fractal == 'j')
		my_julia(mlx);
	if (mlx->fractal == 'b')
		my_burn(mlx);
}

int	arg_check(char *s1, char *s2)
{
	int	n;

	n = 0;
	if (s1[n] == s2[n] + 32 || s1[n] == s2[n])
		n++;
	else
		return (0);
	while (s1[n] != '\0' || s2[n] != '\0')
	{
		if (s1[n] != s2[n])
			return (0);
		n++;
	}
	return (1);
}

int	arg_check2(char *s1)
{
	int	n;
	int	count;

	n = 0;
	count = 0;
	if (s1[n] == '+' || s1[n] == '-')
		n++;
	while (s1[n] != '\0')
	{
		if ((s1[n] < '0' || s1[n] > '9')
			&& s1[n] != '.' && s1[n] != ',')
			return (0);
		if (s1[n] == '.' || s1[n] == ',')
			count++;
		n++;
	}
	if (count > 1)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc >= 2 && arg_check(argv[1], "Mandelbrot"))
		my_mandelbrot_start();
	else if (argc >= 4 && arg_check(argv[1], "Julia")
		&& arg_check2(argv[2]) && arg_check2(argv[3]))
		my_julia_start(my_atof(argv[2]), my_atof(argv[3]));
	else if (argc >= 2 && arg_check(argv[1], "Burningship"))
		my_burn_start();
	else
	{
		write (1, "\nIn order to see the fractal, ", 30);
		write (1, "you must use one of the following parameters:", 45);
		write (1, "\nMandelbrot\nJulia float1 float2\nBurningship\n\n", 45);
		write (1, "Examples:\n   ./fractol Mandelbrot\n", 34);
		write (1, "   ./fractol Julia 0.123 0.321\n", 31);
		write (1, "   ./fractol Burningship\n\n", 26);
	}
}
