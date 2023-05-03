/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehalai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:27:50 by ymehalai          #+#    #+#             */
/*   Updated: 2023/04/13 17:22:40 by ymehalai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ncount(char const *s, char c)
{
	int	i;
	int	len;
	int	res;

	if (!s || *s == 0)
		return (0);
	i = 0;
	res = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		while (*(s + i) == c && *(s + i))
			i++;
		if (*(s + i) != c && *(s + i) != 0)
		{
			res++;
			while (*(s + i) != c && *(s + i))
				i++;
		}
		i++;
	}
	return (res);
}

static void	*free_split(char **spl, int i)
{
	i--;
	while (i >= 0)
	{
		free(spl[i]);
		i--;
	}
	free(spl);
	return (NULL);
}

static char	**fill_tab(char const *s, char **spl, char c, int len)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (i < len)
	{
		while (s[j] == c && s[j])
			j++;
		k = j;
		while (s[k] != c && s[k])
			k++;
		spl[i] = ft_substr(s, j, k - j);
		if (!spl[i])
			return (free_split(spl, i));
		j = k;
		i++;
	}
	spl[len] = NULL;
	return (spl);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		len;

	if (!s)
		return (NULL);
	len = ft_ncount(s, c);
	res = (char **)malloc(sizeof(char *) * (len + 1));
	if (!res)
		return (NULL);
	return (fill_tab(s, res, c, len));
}
