/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaldhahe <zaldhahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:11:55 by zaldhahe          #+#    #+#             */
/*   Updated: 2024/06/14 00:12:03 by zaldhahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	choose_render(t_fractol *f)
{
	mlx_clear_window(f->mlx, f->win);
	if (f->fract == 4)
		mandelrender(f);
	else
		juliarender(f);
}

void	color_change(int keycode, t_fractol *f)
{
	if (keycode == 30)
		f->color += 5;
	else if (keycode == 33)
		f->color -= 5;
	else if (keycode == 18)
		f->color = 0x08;
	else if (keycode == 19)
		f->color = 0x10101a;
	else if (keycode == 20)
		f->color = 0xba000b;
	else if (keycode == 21)
		f->color = 0xc9ccf9;
	else if (keycode == 23)
		f->color = 0xc9cecf;
	else if (keycode == 22)
		f->color = 0xf8a6ff;
	else if (keycode == 26)
		f->color = 0x0c524b;
	else if (keycode == 28)
		f->color = 0xa6c8cc;
	else if (keycode == 25)
		f->color = 0x542d06;
	else if (keycode == 29)
		f->color = 0xf8a2e0;
}

void	move_hook(double x, double y, t_fractol *f)
{
	double	range_r;
	double	range_i;

	if (f->fract == 4)
	{
		range_r = f->max_r - f->min_r;
		range_i = f->max_i - f->min_i;
		f->min_r += x * range_r;
		f->max_r += x * range_r;
		f->min_i += y * range_i;
		f->max_i += y * range_i;
	}
	else
	{
		f->mid_x += x / (f->zoom);
		f->mid_y += y / (f->zoom);
	}
}

int	mouse_hook(int mousecode, int x, int y, t_fractol *f)
{
	(void)x;
	(void)y;
	if (mousecode == 5)
		f->zoom *= 1.1;
	else if (mousecode == 4)
		f->zoom /= 1.1;
	choose_render(f);
	return (0);
}

int	key_hook(int keycode, t_fractol *f)
{
	if (keycode == 53)
		fract_exit(f);
	else if (keycode == 124)
		move_hook(0.1, 0, f);
	else if (keycode == 123)
		move_hook(-0.1, 0, f);
	else if (keycode == 126)
		move_hook(0, -0.1, f);
	else if (keycode == 125)
		move_hook(0, 0.1, f);
	else if (keycode == 12)
		f->max_n -= 25;
	else if (keycode == 14)
		f->max_n += 25;
	else
		color_change(keycode, f);
	choose_render(f);
	return (0);
}
