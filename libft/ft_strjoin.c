/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gberthol <gberthol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:18:39 by gberthol          #+#    #+#             */
/*   Updated: 2023/11/13 13:27:47 by gberthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	size;
	size_t	i;

	size = 0;
	i = 0;
	while (s1[i++])
		size++;
	i = 0;
	while (s2[i++])
		size++;
	res = malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	i = 0;
	size = 0;
	while (s1[i])
		res[size++] = s1[i++];
	i = 0;
	while (s2[i])
		res[size++] = s2[i++];
	res[size] = 0;
	return (res);
}
/*
#include <stdio.h>
int main(int argc, char **argv)
{
	argc = 0;
	printf("%s\n", ft_strjoin(argv[1], argv[2]));
}
*/