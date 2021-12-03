/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 03:42:15 by rkenji-s          #+#    #+#             */
/*   Updated: 2021/12/01 08:27:29 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	my_colors(int keycode, t_data *mlx)
{
	if (keycode == 49)
		mlx->color = 'k';
	else if (keycode == 50)
		mlx->color = 'j';
	else if (keycode == 51)
		mlx->color = 'r';
	else if (keycode == 52)
		mlx->color = 'g';
	else if (keycode == 53)
		mlx->color = 'b';
	my_fractal(mlx);
}

int	get_color(int i, t_data *mlx)
{
	if (mlx->color == 'k')
		return (i * 0x00ABCDEF);
	else if (mlx->color == 'j')
		return (i * 0x00FEDCBA);
	else if (mlx->color == 'r')
		return ((i * 65536) + 1966080);
	else if (mlx->color == 'g')
		return ((i * 256) + 10000);
	else if (mlx->color == 'b')
		return ((i * 256) + 100);
	return (0);
}
