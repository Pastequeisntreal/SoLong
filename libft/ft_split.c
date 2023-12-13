/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gberthol <gberthol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:29:18 by gberthol          #+#    #+#             */
/*   Updated: 2023/11/10 11:06:17 by gberthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	count_word(char const *s, char c)
{
	size_t	i;
	size_t	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		if ((!i || s[i - 1] == c) && s[i] != c)
			word++;
		i++;
	}
	return (word);
}

static char	*ft_strdup_mod(const char *src, char limiter)
{
	char	*res;
	size_t	i;

	i = 0;
	while (src[i] && src[i] != limiter)
		i++;
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (src[i] && src[i] != limiter)
	{
		res[i] = src[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

static void	free_result(char **result)
{
	size_t	i;

	i = 0;
	while (result[i])
		free(result[i++]);
	free(result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;
	size_t	j;

	result = malloc(sizeof(char **) * (count_word(s, c) + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if ((!i || s[i - 1] == c) && s[i] != c)
		{
			result[j] = ft_strdup_mod(&s[i], c);
			if (!result[j])
				return (free_result(result), NULL);
			j++;
		}
		i++;
	}
	result[j] = NULL;
	return (result);
}
