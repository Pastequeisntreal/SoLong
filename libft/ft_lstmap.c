/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gberthol <gberthol@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:56:08 by gberthol          #+#    #+#             */
/*   Updated: 2023/11/14 12:17:47 by gberthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_elem;
	void	*new_content;

	if (!lst || !(*f) || !(*del))
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		new_content = ((*f)(lst->content));
		new_elem = ft_lstnew(new_content);
		if (!new_elem)
			return ((*del)(new_content), ft_lstclear(&new_lst, del), NULL);
		ft_lstadd_back(&new_lst, new_elem);
		lst = lst->next;
	}
	return (new_lst);
}
