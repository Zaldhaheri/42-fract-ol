/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaldhahe <zaldhahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 20:33:43 by zaldhahe          #+#    #+#             */
/*   Updated: 2024/06/13 23:59:43 by zaldhahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx_opengl_20191021/mlx.h"
# include "Libft/libft.h"
# include <unistd.h>
# include <string.h>

# define ERROR_MSG "Enter ./fractol mandelbrot or ./fractol julia <1,2,3>\n"
# define WIDTH 1200
# define HEIGHT 1200

typedef struct s_fractol
{
	int		fract; //0 no fract, 1-3 julia, 4 mandelbrot
	void	*mlx;
	void	*win;
	void	*img;
	int		*data_addr;
	int		color;
	int		bpp;
	int		size_l;
	int		endian;
	double	max_n;
	double	max_i;
	double	min_i;
	double	max_r;
	double	min_r;
	double	cur_x;
	double	cur_y;
	double	old_x;
	double	old_y;
	double	new_x;
	double	new_y;
	double	mid_x;
	double	mid_y;
	double	zoom;
}	t_fractol;

int		check_args(int argc, char *argv[]);
void	get_values(char *argv[], t_fractol *f);
void	choose_render(t_fractol *f);
void	mandelbrot(t_fractol *f);
void	mandelrender(t_fractol *f);
int		get_n(t_fractol *f);
double	get_curr_x(double x, t_fractol *f);
double	get_curr_y(double y, t_fractol *f);
void	julia1(t_fractol *f);
void	julia2(t_fractol *f);
void	julia3(t_fractol *f);
void	juliarender(t_fractol *f);
int		julia_n(t_fractol *f);
int		key_hook(int keycode, t_fractol *f);
int		mouse_hook(int mousecode, int x, int y, t_fractol *f);
void	move_hook(double x, double y, t_fractol *f);
void	color_change(int keycode, t_fractol *f);
void	fract_exit(t_fractol *f);

#endif
