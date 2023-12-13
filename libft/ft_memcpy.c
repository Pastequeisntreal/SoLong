/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gberthol <gberthol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:18:37 by gberthol          #+#    #+#             */
/*   Updated: 2023/11/10 14:48:34 by gberthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	a;

	a = 0;
	if (!dest && !src)
		return (dest);
	while (a < n)
	{
		((char *)dest)[a] = ((char *)src)[a];
		a++;
	}
	return (dest);
}

/*
#include <stdio.h>
int main(void)
{
	int	a[6] = {1,2,3,4,5,6};
	int	b[6];

	ft_memcpy(b, a, sizeof(int) * 6);
	for (int i = 0; i < 6; i++)
		printf("[%d] ", b[i]);
	printf("\n");
	return 0;
}
*/
