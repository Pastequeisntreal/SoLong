/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gberthol <gberthol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:32:58 by gberthol          #+#    #+#             */
/*   Updated: 2023/11/09 16:21:52 by gberthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*cpy;

	i = 0;
	while (s[i])
		i++;
	cpy = malloc(sizeof(char) * (i + 1));
	if (!cpy)
		return (NULL);
	i = 0;
	while (s[i])
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = 0;
	return (cpy);
}

/*
#include <stdio.h>
int main(int argc, char **argv)
{
	argc = 0;
	printf("%s\n", ft_strdup(argv[1]));
}
*/
