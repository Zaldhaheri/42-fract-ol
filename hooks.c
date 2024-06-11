/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaldhahe <zaldhahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:11:55 by zaldhahe          #+#    #+#             */
/*   Updated: 2024/06/11 20:24:33 by zaldhahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void fract_exit(t_fractol *f)
{
	mlx_destroy_image(f->mlx, f->img);
	mlx_destroy_window(f->mlx, f->win);
	exit(0);
}

void move_hook(double x, double y, t_fractol *f)
{
	double	range_r;
	double	range_i;

	range_r = f->max_r - f->min_r;
	range_i= f->max_i - f->min_i;
	f->min_r += x * range_r;
	f->max_r += x * range_r;
	f->min_i += y * range_i;
	f->max_i += y * range_i;
}

int mouse_hook(int mousecode, int x, int y, t_fractol *f)
{
	(void)x;
	(void)y;
	if (mousecode == 5)
		f->zoom*=1.2;
	else if (mousecode == 4)
		f->zoom/=1.2;
	if (f->fract == 1)
	{
		mlx_clear_window(f->mlx, f->win);
		mandelrender(f);
	}
	return (0);
}

int	key_hook(int keycode, t_fractol *f)
{
	if (keycode == 53)
		fract_exit(f);
	else if(keycode == 33)
		f->color-= 50;
	else if (keycode == 30)
		f->color+=50;
	else if (keycode == 124)
		move_hook(0.1, 0, f);
	else if (keycode == 123)
		move_hook(-0.1, 0, f);
	else if (keycode == 126)
		move_hook(0, -0.1, f);
	else if (keycode == 125)
		move_hook(0, 0.1, f);
	else
		printf("keycode: %d\n", keycode);
	mlx_clear_window(f->mlx, f->win);
	mandelrender(f);
	return (0);
}
