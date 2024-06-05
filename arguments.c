/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaldhahe <zaldhahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:30:11 by zaldhahe          #+#    #+#             */
/*   Updated: 2024/06/05 18:58:18 by zaldhahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int check_args(int argc, char *argv[])
{
    if (!((argc == 2 && !ft_strncmp("mandelbrot", argv[1], 11)) ||
        (argc == 3 && !ft_strncmp("julia", argv[1], 6))))
    {
        ft_putstr_fd(ERROR_MSG, 1);
        return(0);
    }
    return (1);
}

void get_values(int argc, char *argv[], t_fractol *f)
{
    if (!ft_strncmp("mandelbrot", argv[1], 11))
    {
        mandelbrot(&f);
    }
    else if (!ft_strncmp("julia", argv[1], 6) && argv[2] == "1")
    {
        julia1(&f);
    }
    else if (!ft_strncmp("julia", argv[1], 6) && argv[2] == "2")
    {
        julia2(&f);
    }
    else if (!ft_strncmp("julia", argv[1], 6) && argv[2] == "3")
    {
        julia3(&f);
    }
}
