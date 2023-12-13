/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gberthol <gberthol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:21:29 by gberthol          #+#    #+#             */
/*   Updated: 2023/11/10 10:29:06 by gberthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	a;

	a = 0;
	while (a < n)
		((unsigned char *)s)[a++] = c;
	return (s);
}

/*
#include <stdio.h>
int main(void)
{
	char	s[5];

	ft_memset(s, 'p', 4);
	s[4] = 0;
	printf("%s\n", s);
}
*/
