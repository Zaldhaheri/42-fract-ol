/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaldhahe <zaldhahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:30:11 by zaldhahe          #+#    #+#             */
/*   Updated: 2024/06/13 23:02:54 by zaldhahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_julia(char *argv[])
{
	if (!ft_strncmp("1", argv[2], 2))
		return (1);
	if (!ft_strncmp("2", argv[2], 2))
		return (1);
	if (!ft_strncmp("3", argv[2], 2))
		return (1);
	return (0);
}

int	check_args(int argc, char *argv[])
{
	int	x;

	x = 0;
	if (argc == 2 && !ft_strncmp("mandelbrot", argv[1], 11))
		x = 1;
	else if (argc == 3 && check_julia(argv) && !ft_strncmp("julia", argv[1], 6))
		x = 1;
	if (!x)
		ft_putstr_fd(ERROR_MSG, 1);
	return (x);
}

void	get_values(char *argv[], t_fractol *f)
{
	if (!ft_strncmp("mandelbrot", argv[1], 11))
		mandelbrot(f);
	else if (!ft_strncmp("julia", argv[1], 6) && !ft_strncmp("1", argv[2], 2))
		julia1(f);
	else if (!ft_strncmp("julia", argv[1], 6) && !ft_strncmp("2", argv[2], 2))
		julia2(f);
	else if (!ft_strncmp("julia", argv[1], 6) && !ft_strncmp("3", argv[2], 2))
		julia3(f);
}
