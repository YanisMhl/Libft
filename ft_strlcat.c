/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehalai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:06:33 by ymehalai          #+#    #+#             */
/*   Updated: 2023/04/05 15:59:08 by ymehalai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	l;

	if (dstsize == 0 && (!dst || !src))
		return (0);
	i = 0;
	k = ft_strlen(dst);
	l = ft_strlen(src);
	if (dstsize == 0 || dstsize <= k)
		return (dstsize + l);
	while (*(dst + i))
		i++;
	j = 0;
	while (i < dstsize - 1 && *(src + j))
	{
		*(dst + i) = *(src + j);
		i++;
		j++;
	}
	*(dst + i) = '\0';
	return (k + l);
}
