/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaldhahe <zaldhahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 20:33:35 by zaldhahe          #+#    #+#             */
/*   Updated: 2024/06/06 22:27:44 by zaldhahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void clear_struct(t_fractol *f)
{
	f->fract = 0;
	f->mlx = 0;
	f->win = 0;
	f->img = 0;
	f->data_addr = 0;
	f->cur_x = 0;
	f->cur_y = 0;
	f->bpp = 0;
	f->size_l = 0;
	f->endian = 0;
}

int	main(int argc, char *argv[])
{
	t_fractol f;
	
	if (!check_args(argc, argv))
		return (0);
	clear_struct(&f);
	get_values(argv, &f);
	
	mlx_loop(f.mlx);
}
