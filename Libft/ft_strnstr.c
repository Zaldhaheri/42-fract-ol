/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaldhahe <zaldhahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 23:04:08 by zaldhahe          #+#    #+#             */
/*   Updated: 2024/01/15 12:50:19 by zaldhahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	len;

	len = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	if (n == 0)
		return (NULL);
	len = ft_strlen(needle);
	while (*haystack && len <= n)
	{
		if (!(ft_strncmp(haystack, (char *)needle, len)))
			return ((char *)haystack);
		haystack++;
		n--;
	}
	return (NULL);
}
