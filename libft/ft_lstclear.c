/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gberthol <gberthol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:54:03 by gberthol          #+#    #+#             */
/*   Updated: 2023/11/13 16:28:21 by gberthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*save;

	if (!lst || !lst[0])
		return ;
	while (*lst)
	{
		save = (*lst)->next;
		(*del)((*lst)->content);
		free(*lst);
		*lst = save;
	}
}
