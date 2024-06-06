/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaldhahe <zaldhahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 20:33:43 by zaldhahe          #+#    #+#             */
/*   Updated: 2024/06/06 22:27:23 by zaldhahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx_opengl_20191021/mlx.h"
# include "libft/libft.h"
# include <unistd.h>
# include <string.h>

# define ERROR_MSG "Enter ./fractol mandelbrot or ./fractol julia <set>\n"
# define WIDTH 800
# define HEIGHT 800

typedef struct s_fractol
{
	int fract; //0 no fract, 1 mandelbrot, 2 julia
	void *mlx;
	void *win;
	void *img;
	int *data_addr;
	int color;
	int bpp;
	int size_l;
	int endian;
	double max_i;
	double min_i;
	double max_r;
	double min_r;
	double cur_x;
	double cur_y;
}	t_fractol;

int check_args(int argc, char *argv[]);
void get_values(char *argv[], t_fractol *f);
void mandelbrot(t_fractol *f);

#endif
