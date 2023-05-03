/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehalai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:12:24 by ymehalai          #+#    #+#             */
/*   Updated: 2023/04/13 17:23:09 by ymehalai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_count(long int n)
{
	int	res;

	res = 1;
	if (n < 0)
	{
		res++;
		n = -n;
	}
	while (n > 9)
	{
		res++;
		n /= 10;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	long int	nb;
	int			i;
	int			len;
	char		*res;

	nb = n;
	len = nb_count(n);
	i = len;
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	if (nb < 0)
	{
		*res = '-';
		nb = -nb;
	}
	*(res + len) = '\0';
	while (--i >= (n < 0))
	{
		*(res + i) = (nb % 10) + '0';
		nb /= 10;
	}
	return (res);
}
