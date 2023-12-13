/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gberthol <gberthol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:51:04 by gberthol          #+#    #+#             */
/*   Updated: 2023/11/10 13:34:37 by gberthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	inside(char c, char const *set)
{
	unsigned int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	test_empty(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	still;

	i = 0;
	while (s1[i])
	{
		j = 0;
		still = 0;
		while (set[j])
		{
			if (set[j] == s1[i])
				still = 1;
			j++;
		}
		if (!still)
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	save;
	char	*res;

	i = 0;
	if (test_empty(s1, set))
		return (ft_calloc(1, sizeof(char)));
	while (s1[i] && inside(s1[i], set))
		i++;
	j = ft_strlen(s1) - 1;
	while (j > 0 && inside(s1[j], set))
		j -= 1;
	j += 1;
	res = malloc(sizeof(char) * (j - i + 1));
	if (!res)
		return (NULL);
	save = i;
	while (s1[i] && i < j)
	{
		res[i - save] = s1[i];
		i++;
	}
	res[i - save] = 0;
	return (res);
}

/*
#include <stdio.h>
int main(int argc, char **argv)
{
	argc = 0;
	printf("%s\n", ft_strtrim(argv[1], argv[2]));
}
*/
