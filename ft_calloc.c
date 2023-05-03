/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehalai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:39:02 by ymehalai          #+#    #+#             */
/*   Updated: 2023/04/10 16:05:32 by ymehalai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	size_t	range;
	void	*result;

	range = count * size;
	if (size != 0 && count != (range / size))
		return (NULL);
	i = 0;
	result = malloc(count * size);
	if (!result)
		return (NULL);
	while (i < count * size)
	{
		*((unsigned char *)result + i) = 0;
		i++;
	}
	return (result);
}
