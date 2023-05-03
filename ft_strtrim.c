/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehalai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:11:59 by ymehalai          #+#    #+#             */
/*   Updated: 2023/04/13 17:22:07 by ymehalai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_inset(char c, char const *set)
{
	int	i;

	i = 0;
	if (!set)
		return (1);
	while (*(set + i))
	{
		if (*(set + i) == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		i;
	int		j;

	if (!s1 || !set)
		return (NULL);
	if (*s1 == 0)
	{
		res = malloc(1);
		if (!res)
			return (NULL);
		*res = '\0';
		return (res);
	}
	i = 0;
	while (ft_inset(*(s1 + i), set) && *(s1 + i))
		i++;
	j = ft_strlen(s1) - 1;
	while (ft_inset(*(s1 + j), set) && *(s1 + j))
		j--;
	if (i > j)
		j = i - 1;
	return (ft_substr(s1, i, j - i + 1));
}
