/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaldhahe <zaldhahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 22:27:16 by zaldhahe          #+#    #+#             */
/*   Updated: 2023/12/25 22:28:24 by zaldhahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numlen(long n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*itoa;
	int			len;
	long long	nl;

	nl = n;
	len = ft_numlen(nl);
	itoa = malloc(sizeof(char) * (len + 1));
	if (!(itoa))
		return (NULL);
	itoa[len--] = '\0';
	if (nl == 0)
		itoa[0] = '0';
	else if (nl < 0)
	{
		itoa[0] = '-';
		nl = -nl;
	}
	while (nl > 0)
	{
		itoa[len--] = (nl % 10) + 48;
		nl /= 10;
	}
	return (itoa);
}
