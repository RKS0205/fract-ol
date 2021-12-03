/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 21:33:06 by rkenji-s          #+#    #+#             */
/*   Updated: 2021/12/01 08:27:33 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	my_julia_formula(float x, float y, t_data *mlx)
{
	int		i;
	float	zx;
	float	zy;
	float	tmp;

	zx = x;
	zy = y;
	i = 1;
	while (i < MAX_ITER)
	{
		tmp = zx;
		zx = ((zx * zx) - (zy * zy)) + mlx->julia_x;
		zy = (2 * tmp * zy) + mlx->julia_y;
		if ((zx * zx) + (zy * zy) > 4)
		{
			my_img_pixel_put(mlx, mlx->px, mlx->py, get_color(i, mlx));
			return (i);
		}
		i++;
	}
	my_img_pixel_put(mlx, mlx->px, mlx->py, 0);
	return (i);
}

void	my_julia(t_data *mlx)
{
	float	x;
	float	y;

	mlx->img = mlx_new_image(mlx->mlx, IMG_X, IMG_Y);
	mlx->img_addr = mlx_get_data_addr(mlx->img, &mlx->img_bits_per_pixel,
			&mlx->img_line_length, &mlx->img_endian);
	mlx->px = 0;
	mlx->py = 0;
	while (mlx->py <= IMG_Y)
	{
		while (mlx->px <= IMG_X)
		{
			x = mlx->x_min + (mlx->px * ((mlx->x_max - mlx->x_min) / IMG_X));
			y = mlx->y_max - (mlx->py * ((mlx->y_max - mlx->y_min) / IMG_Y));
			my_julia_formula(x, y, mlx);
			mlx->px++;
		}
		mlx->py++;
		mlx->px = 0;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	mlx_destroy_image(mlx->mlx, mlx->img);
}

void	my_julia_start(float x, float y)
{
	t_data	*mlx;

	mlx = (t_data *) malloc (sizeof (t_data));
	mlx->fractal = 'j';
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, IMG_X, IMG_Y, "Fract-ol");
	mlx->x_min = MIN_X;
	mlx->x_max = MAX_X;
	mlx->y_min = MIN_Y;
	mlx->y_max = MAX_Y;
	mlx->julia_x = x;
	mlx->julia_y = y;
	mlx->color = 'k';
	my_julia(mlx);
	mlx_mouse_hook(mlx->win, my_zoom, mlx);
	mlx_key_hook(mlx->win, my_buttons, mlx);
	mlx_expose_hook(mlx->win, (void *)my_fractal, mlx);
	mlx_loop(mlx->mlx);
}
