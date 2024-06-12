/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaldhahe <zaldhahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:58:26 by zaldhahe          #+#    #+#             */
/*   Updated: 2024/06/12 20:08:01 by zaldhahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//xtemp = x^2 - y^2 + max_r
//y = 2*x*y + max_i
//x = xtemp

// xtemp = f->cur_x*f->cur_x - f->cur_x*f->cur_y + f->max_r;
// f->cur_y = 2 * f->cur_x * f->cur_y + f->max_i;
// f->cur_x = xtemp;

//problem: zooming in rerenders everything making zoom slow and oher key inputs slower.
int get_n(t_fractol *f)
{
    int i;
    double x;
    double y;
    double temp;

    x = 0.0;
    y = 0.0;
    i = 0.0;
    while(i < 100 && (x * x) + (y * y) < 4.0)
    {
        temp = x * x - y * y + f->cur_x;
        y = 2.0 * x * y + f->cur_y;
        x = temp;
        i++;
    }
    return (i);
}

double get_curr_x(double x, t_fractol *f)
{
    double  range;
    
    range = f->max_r - f->min_r;
    return(x * (range / WIDTH) + f->min_r);
}

double get_curr_y(double y, t_fractol *f)
{
    double  range;
    
    range = f->max_i - f->min_i;
    return(y * (range / HEIGHT) + f->min_i);
}

void mandelrender(t_fractol *f)
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

void mandelbrot(t_fractol *f)
{
    //Z(n+1) = Z(n)^2 + c or just Z(n)*Z(n) + c
    f->fract = 4;
    f->max_i = 1;
    f->min_i = -1;
    f->max_r = 0.5;
    f->min_r = -2.0;
    f->zoom = 1;
    f->color = 0x08;
    f->mlx = mlx_init();
    f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "mandelbrot");
    f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
    f->data_addr = (int *) mlx_get_data_addr(f->img, &f->bpp, &f->size_l, &f->endian);
    mandelrender(f);
}
