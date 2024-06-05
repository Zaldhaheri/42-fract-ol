/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaldhahe <zaldhahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 20:33:43 by zaldhahe          #+#    #+#             */
/*   Updated: 2024/06/05 18:55:52 by zaldhahe         ###   ########.fr       */
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
	
}	t_fractol;

int check_args(int argc, char *argv[]);

#endif
