/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaldhahe <zaldhahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:03:43 by zaldhahe          #+#    #+#             */
/*   Updated: 2024/06/12 20:13:24 by zaldhahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void julia1(t_fractol *f)
{
	f->fract = 1;
    f->max_i = 1;
    f->min_i = -1;
    f->max_r = 0.5;
    f->min_r = -1.0;
    f->zoom = 1;
    f->color = 0x08;
    f->mlx = mlx_init();
    f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "julia 1");
    f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
    f->data_addr = (int *) mlx_get_data_addr(f->img, &f->bpp, &f->size_l, &f->endian);
    mandelrender(f);
}

void julia2(t_fractol *f)
{
    f->fract = 2;
    f->max_i = 1;
    f->min_i = -1;
    f->max_r = 0.5;
    f->min_r = -2.0;
    f->zoom = 1;
    f->color = 0x08;
    f->mlx = mlx_init();
    f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "julia 2");
    f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
    f->data_addr = (int *) mlx_get_data_addr(f->img, &f->bpp, &f->size_l, &f->endian);
    mandelrender(f);
}

void julia3(t_fractol *f)
{
    f->fract = 3;
    f->max_i = 1;
    f->min_i = -1;
    f->max_r = 0.5;
    f->min_r = -2.0;
    f->zoom = 1;
    f->color = 0x08;
    f->mlx = mlx_init();
    f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "julia 3");
    f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
    f->data_addr = (int *) mlx_get_data_addr(f->img, &f->bpp, &f->size_l, &f->endian);
    mandelrender(f);
}

void juliarender(t_fractol *f)
{
	int x;
    int y;
    int n;

    x = 0;
    while (x < WIDTH)
    {
        y = 0;
        while (y < HEIGHT)
        {
            f->cur_x = get_curr_x(x, f) * 1.1 * f->zoom;
            f->cur_y = get_curr_y(y, f) * 1.1 * f->zoom;
            n = get_n(f);
            f->data_addr[y * WIDTH + x] = f->color * n;
            y++;
        }
        x++;
    }
    mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}