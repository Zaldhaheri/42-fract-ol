/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaldhahe <zaldhahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:03:43 by zaldhahe          #+#    #+#             */
/*   Updated: 2024/06/13 23:17:29 by zaldhahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_n(t_fractol *f)
{
	int	i;

	i = 0;
	if (f->max_n > 300)
		f->max_n = 300;
	else if (f->max_n < 25)
		f->max_n = 25;
	while (i < f->max_n && (f->new_x * f->new_x) + (f->new_y * f->new_y) < 4.0)
	{
		f->old_x = f->new_x;
		f->old_y = f->new_y;
		f->new_x = f->old_x * f->old_x - f->old_y * f->old_y + f->cur_x;
		f->new_y = 2 * f->old_x * f->old_y + f->cur_y;
		i++;
	}
	return (i);
}

void	julia1(t_fractol *f)
{
	f->fract = 1;
	f->max_n = 300;
	f->cur_x = -0.835;
	f->cur_y = -0.2321;
	f->old_x = 0;
	f->old_y = 0;
	f->new_x = 0;
	f->new_y = 0;
	f->mid_x = 0;
	f->mid_y = 0;
	f->zoom = 1;
	f->color = 0x08;
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "julia 1");
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->data_addr = (int *) mlx_get_data_addr(f->img,
			&f->bpp, &f->size_l, &f->endian);
	juliarender(f);
}

void	julia2(t_fractol *f)
{
	f->fract = 2;
	f->max_n = 300;
	f->cur_x = -0.4;
	f->cur_y = -0.6;
	f->old_x = 0;
	f->old_y = 0;
	f->new_x = 0;
	f->new_y = 0;
	f->mid_x = 0;
	f->mid_y = 0;
	f->zoom = 1;
	f->color = 0x08;
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "julia 2");
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->data_addr = (int *) mlx_get_data_addr(f->img,
			&f->bpp, &f->size_l, &f->endian);
	juliarender(f);
}

void	julia3(t_fractol *f)
{
	f->fract = 3;
	f->max_n = 300;
	f->cur_x = 0.285;
	f->cur_y = -0.01;
	f->old_x = 0;
	f->old_y = 0;
	f->new_x = 0;
	f->new_y = 0;
	f->mid_x = 0;
	f->mid_y = 0;
	f->zoom = 1;
	f->color = 0x08;
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "julia 3");
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->data_addr = (int *) mlx_get_data_addr(f->img,
			&f->bpp, &f->size_l, &f->endian);
	juliarender(f);
}

void	juliarender(t_fractol *f)
{
	int	x;
	int	y;
	int	n;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			f->new_x = 1.2 * (x - WIDTH / 2 + f->mid_x * WIDTH)
				/ (0.3 * f->zoom * WIDTH);
			f->new_y = 1.2 * (y - HEIGHT / 2 + f->mid_y * HEIGHT)
				/ (0.3 * f->zoom * HEIGHT);
			n = julia_n(f);
			f->data_addr[y * WIDTH + x] = f->color * n;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
