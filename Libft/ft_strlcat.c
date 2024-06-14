/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaldhahe <zaldhahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 23:22:37 by zaldhahe          #+#    #+#             */
/*   Updated: 2024/01/22 13:00:37 by zaldhahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	x;
	size_t	dlen;
	size_t	slen;

	i = 0;
	dlen = 0;
	slen = 0;
	if (n == 0)
		return (ft_strlen(src));
	while (dest[dlen] && dlen < n)
		dlen++;
	while (src[slen])
		slen++;
	if (dlen == n)
		return (dlen + slen);
	x = dlen;
	while (src[i] && x < n - 1 && n > 0)
		dest[x++] = src[i++];
	dest[x] = '\0';
	return (dlen + slen);
}
