/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaldhahe <zaldhahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 23:26:13 by zaldhahe          #+#    #+#             */
/*   Updated: 2024/01/16 14:10:31 by zaldhahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*r;
	size_t			i;
	unsigned int	strlen;

	i = 0;
	strlen = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start >= strlen)
		return (ft_strdup(""));
	if (len + start >= strlen)
		len = strlen - start;
	r = malloc(sizeof(char) * len + 1);
	if (!r)
		return (NULL);
	while (s[start] && i < len)
		r[i++] = s[start++];
	r[i] = '\0';
	return (r);
}
