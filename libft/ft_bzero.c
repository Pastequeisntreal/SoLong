/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gberthol <gberthol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:51:21 by gberthol          #+#    #+#             */
/*   Updated: 2023/11/09 15:56:52 by gberthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_bzero(void *s, size_t n)
{
	size_t	a;

	a = 0;
	while (a < n)
		((char *)s)[a++] = 0;
	return (s);
}

/*
#include <stdio.h>
int	main(void)
{
	int tab[] = {1,2,3,4,5};

	for (int i = 0; i < 5; i++)
		printf("[%d]", tab[i]);
	printf("\n");
	ft_bzero(tab, 5 * sizeof(int));
	for (int i = 0; i < 5; i++)
		printf("[%d]", tab[i]);
	printf("\n");
}
*/
