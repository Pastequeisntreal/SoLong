/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gberthol <gberthol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:05:50 by gberthol          #+#    #+#             */
/*   Updated: 2023/11/10 15:20:35 by gberthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((unsigned char)c == 0)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	res;

	i = 0;
	res = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			res = i;
		i++;
	}
	if ((unsigned char)c == 0)
		return ((char *)&s[i]);
	if (!res && s[0] != (unsigned char)c)
		return (NULL);
	return ((char *)&s[res]);
}

/*
#include <stdio.h>
int main(int argc, char **argv)
{
	argc = 0;
	printf("%s\n", strchr(argv[1], argv[2][0]));
	printf("%s\n", strrchr(argv[1], argv[2][0]));
}
*/
