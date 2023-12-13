/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gberthol <gberthol@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:35:19 by gberthol          #+#    #+#             */
/*   Updated: 2023/12/04 15:05:25 by gberthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strenddupcat(char *dst, const char *src, char end)
{
	size_t	size;
	size_t	i;
	size_t	x;
	char	*res;

	if (!src || !dst || !end)
		return (dst);
	size = ft_strlen(dst);
	i = 0;
	while (src[i] && src[i++ - 1] != '\n')
		size++;
	res = malloc(sizeof(char) * (size + 1));
	if (!res)
		return (free(dst), NULL);
	i = 0;
	x = 0;
	while (dst[++i - 1])
		res[i - 1] = dst[i - 1];
	while (src[x] && src[x - 1] != end)
	{
		res[i + x - 1] = src[x];
		x++;
	}
	res[i + x - 1] = 0;
	return (free(dst), res);
}

char	*ft_strenddup(char *src, char end)
{
	char	*dest;
	size_t	i;

	i = 0;
	while (src[i] && src[i] != end)
		i++;
	if (src[i] == end)
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i] && src[i] != end)
	{
		dest[i] = src[i];
		i++;
	}
	if (src[i] == end)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
