/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gberthol <gberthol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:55:54 by gberthol          #+#    #+#             */
/*   Updated: 2023/11/10 14:42:59 by gberthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	save;

	i = 0;
	if (!(unsigned char)little[0])
		return ((char *)big);
	while (i < len && big[i])
	{
		j = 0;
		save = i;
		while (little[j] && little[j] == big[save] && save < len)
		{
			j++;
			save++;
		}
		if (!little[j])
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
