/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gberthol <gberthol@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:49:06 by gberthol          #+#    #+#             */
/*   Updated: 2023/12/11 12:49:06 by gberthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	free_map(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

char	**doublearrdup(char **tab)
{
	size_t	size;
	size_t	i;
	char	**cpy;

	if (!tab)
		return (NULL);
	size = 0;
	while (tab[size])
		size++;
	cpy = ft_calloc(size + 1, sizeof(char *));
	if (!cpy)
		return (NULL);
	i = 0;
	while (tab[i])
	{
		cpy[i] = ft_strdup(tab[i]);
		if (!cpy[i])
			return (free_map(cpy), NULL);
		i++;
	}
	return (cpy);
}
