/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehalai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:24:07 by ymehalai          #+#    #+#             */
/*   Updated: 2023/04/13 17:28:25 by ymehalai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_ptr;

	if (!lst || !del)
		return ;
	while (*lst != NULL)
	{
		next_ptr = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next_ptr;
	}
}
