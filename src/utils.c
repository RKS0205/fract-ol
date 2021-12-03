/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 21:33:03 by rkenji-s          #+#    #+#             */
/*   Updated: 2021/12/01 08:27:37 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	my_img_pixel_put(t_data *mlx, int x, int y, int color)
{
	char	*byte;

	byte = mlx->img_addr + ((y * mlx->img_line_length)
			+ (x * mlx->img_bits_per_pixel / 8));
	*(unsigned int *)byte = color;
}

int	my_arrows(int keycode, t_data *mlx)
{
	float	dx;
	float	dy;

	dx = (mlx->x_max - mlx->x_min);
	dy = (mlx->y_max - mlx->y_min);
	if (keycode == 65361 || keycode == 65363)
	{
		if (keycode == 65361)
			dx *= -1;
		mlx->x_min += dx / 3.0;
		mlx->x_max += dx / 3.0;
	}
	if (keycode == 65362 || keycode == 65364)
	{
		if (keycode == 65364)
			dy *= -1;
		mlx->y_min += dy / 3.0;
		mlx->y_max += dy / 3.0;
	}
	my_fractal(mlx);
	return (0);
}

int	my_buttons(int keycode, t_data *mlx)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		mlx_destroy_display(mlx->mlx);
		free (mlx->mlx);
		free (mlx);
		exit (0);
	}
	my_arrows(keycode, mlx);
	my_colors(keycode, mlx);
	return (0);
}

int	my_zoom(int keycode, int x, int y, t_data *mlx)
{
	float	dx;
	float	dy;

	dx = (mlx->x_max - mlx->x_min) / IMG_X;
	dy = (mlx->y_max - mlx->y_min) / IMG_Y;
	if (keycode == 4)
	{
		mlx->x_min = (mlx->x_min + ((x * dx) * 0.5));
		mlx->x_max = (mlx->x_max - (((IMG_X - x) * dx) * 0.5));
		mlx->y_min = (mlx->y_min + (((IMG_Y - y) * dy) * 0.5));
		mlx->y_max = (mlx->y_max - ((y * dy) * 0.5));
	}
	if (keycode == 5)
	{
		mlx->x_min = (mlx->x_min - ((x * dx) * 0.5));
		mlx->x_max = (mlx->x_max + (((IMG_X - x) * dx) * 0.5));
		mlx->y_min = (mlx->y_min - (((IMG_Y - y) * dy) * 0.5));
		mlx->y_max = (mlx->y_max + ((y * dy) * 0.5));
	}
	my_fractal(mlx);
	return (0);
}

float	my_atof(char *s)
{
	float	n;
	float	d;
	int		sign;
	int		count;

	count = 0;
	sign = 1;
	d = 1;
	n = 0;
	if (s[count] == '-' || s[count] == '+')
	{
		if (s[count++] == '-')
			sign = -1;
	}
	while (s[count] >= '0' && s[count] <= '9')
		n = (float)(n * 10) + (float)(s[count++] - 48);
	if ((s[count] == '.' || s[count] == ',') && s[++count] != '\0')
	{
		while (s[count] >= '0' && s[count] <= '9')
		{
			d *= 10;
			n = (float)(n * 10) + (float)(s[count++] - 48);
		}
	}
	return ((n / d) * sign);
}
