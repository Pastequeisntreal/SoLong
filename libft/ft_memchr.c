/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gberthol <gberthol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:09:58 by gberthol          #+#    #+#             */
/*   Updated: 2023/11/10 14:05:08 by gberthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return (&((char *)s)[i]);
		i++;
	}
	return (NULL);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	if (!n)
		return (0);
	return (((unsigned char *)s1)[i - 1] - ((unsigned char *)s2)[i - 1]);
}

/*
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
*/
/*
int	main(int argc, char **argv)
{
	argc = 0;
	printf("%s\n", (char *)ft_memchr(argv[1], argv[2][0], strlen(argv[1])));
}
*/
/*
int	main(int argc, char **argv)
{
	argc = 0;
	printf("%d\n", ft_memcmp(argv[1], argv[2], atoi(argv[3])));
	printf("%d\n", memcmp(argv[1], argv[2], atoi(argv[3])));
}
*/
