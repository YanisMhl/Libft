/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehalai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:05:08 by ymehalai          #+#    #+#             */
/*   Updated: 2023/04/10 16:01:17 by ymehalai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	count;
	size_t	i;
	size_t	j;

	i = 0;
	if (!haystack && len == 0)
		return (NULL);
	if (*needle == 0)
		return ((char *)haystack);
	while (i < len && *(haystack + i))
	{
		j = i;
		count = 0;
		while (*(needle + count) == *(haystack + j)
			&& j < len && *(needle + count))
		{
			count++;
			j++;
		}
		if (count == ft_strlen(needle))
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
