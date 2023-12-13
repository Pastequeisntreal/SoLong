/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gberthol <gberthol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:51:54 by gberthol          #+#    #+#             */
/*   Updated: 2023/11/13 11:09:59 by gberthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*error_start(void)
{
	char	*res;

	res = malloc(sizeof(char));
	if (!res)
		return (NULL);
	res[0] = 0;
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	save;
	char			*res;
	size_t			size;

	save = start;
	size = ft_strlen(s);
	if (start > size)
		return (error_start());
	if (size - start < len)
		res = malloc(sizeof(char) * (size - start + 1));
	else
		res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (s[start] && start - save < (unsigned int)len)
	{
		res[start - save] = s[start];
		start++;
	}
	res[start - save] = 0;
	return (res);
}

/*
#include <stdio.h>
int main(int argc, char **argv)
{
	argc = 0;
	printf("%s\n", ft_substr(argv[1], atoi(argv[2]), atoi(argv[3])));
}
*/
