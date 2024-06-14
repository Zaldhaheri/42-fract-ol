/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaldhahe <zaldhahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 22:24:50 by zaldhahe          #+#    #+#             */
/*   Updated: 2024/01/22 10:54:56 by zaldhahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*r;

	if (size && SIZE_MAX / size < nitems)
		return (NULL);
	r = malloc(size * nitems);
	if (!r)
		return (NULL);
	ft_bzero(r, size * nitems);
	return (r);
}
