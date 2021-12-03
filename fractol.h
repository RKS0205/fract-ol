/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 21:33:09 by rkenji-s          #+#    #+#             */
/*   Updated: 2021/12/02 18:48:11 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define MAX_ITER 500
# define MIN_X -2
# define MAX_X 2
# define MIN_Y -2
# define MAX_Y 2
# define IMG_Y 600.0
# define IMG_X 600.0

# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <math.h>
# include <unistd.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_addr;
	int		fractal;
	int		color;
	int		img_bits_per_pixel;
	int		img_line_length;
	int		img_endian;
	int		px;
	int		py;
	float	x_min;
	float	x_max;
	float	y_min;
	float	y_max;
	float	julia_x;
	float	julia_y;
}	t_data;

void	my_img_pixel_put(t_data *mlx, int x, int y, int color);
int		my_mandelbrot_formula(float x, float y, t_data *mlx);
void	my_mandelbrot(t_data *mlx);
int		my_arrows(int keycode, t_data *mlx);
int		my_buttons(int keycode, t_data *mlx);
int		my_zoom(int keycode, int x, int y, t_data *mlx);
void	my_mandelbrot_start(void);
int		arg_check(char *s1, char *s2);
int		arg_check2(char *s1);
void	my_fractal(t_data *mlx);
float	my_atof(char *s);
void	my_julia_start(float x, float y);
void	my_julia(t_data *mlx);
int		my_julia_formula(float x, float y, t_data *mlx);
int		my_burn_formula(float x, float y, t_data *mlx);
void	my_burn(t_data *mlx);
void	my_burn_start(void);
void	my_colors(int keycode, t_data *mlx);
int		get_color(int i, t_data *mlx);
#endif