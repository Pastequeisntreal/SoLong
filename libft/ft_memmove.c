/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gberthol <gberthol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:48:58 by gberthol          #+#    #+#             */
/*   Updated: 2023/11/10 11:42:38 by gberthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, void const *src, size_t n)
{
	size_t	i;

	if (dst > src)
	{
		while (n)
		{
			n -= 1;
			((unsigned char *)dst)[n] = ((unsigned char *)src)[n];
		}
	}
	else if (dst < src)
	{
		i = 0;
		while (i < n)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}
