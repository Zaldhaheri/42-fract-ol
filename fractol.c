/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaldhahe <zaldhahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 20:33:35 by zaldhahe          #+#    #+#             */
/*   Updated: 2024/06/04 21:59:52 by zaldhahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol fractol;
	
	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 11))
		|| (argc == 4 && !ft_strncmp(argv[1], "julia", 6)))
	{
		fractol.name = argv[1];
		mlx_new_image(&fractol, 800, 800);
		mlx_new_window(&fractol, 800, 800, "fractol");
		mlx_loop(&fractol);
		//rendering
		//loop
	}
	else
		ft_putstr_fd(ERROR_MSG, 1);
	return (0);
}