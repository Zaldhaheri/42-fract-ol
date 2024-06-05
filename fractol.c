/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaldhahe <zaldhahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 20:33:35 by zaldhahe          #+#    #+#             */
/*   Updated: 2024/06/05 18:47:39 by zaldhahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void clear_struct(t_fractol *f)
{
	f->fract = 0;
	f->mlx = 0;
	f->win = 0;
	f->img = 0;
}

int	main(int argc, char *argv[])
{
	t_fractol fractol;
	
	if (!check_args(argc, argv))
		return (0);
	clear_struct(&fractol);
	//get_values(argc, argv, &fractol);
	
}
