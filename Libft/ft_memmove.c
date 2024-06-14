/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaldhahe <zaldhahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 22:44:22 by zaldhahe          #+#    #+#             */
/*   Updated: 2024/01/18 17:25:42 by zaldhahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	char	*dest;
	char	*src;
	size_t	i;

	dest = (char *)str1;
	src = (char *)str2;
	i = n;
	if (!dest && !src)
		return (0);
	if (dest > src)
	{
		while (i--)
			dest[i] = src[i];
	}
	else
		ft_memcpy(dest, src, n);
	return (str1);
}
