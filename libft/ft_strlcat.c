/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gberthol <gberthol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:06:33 by gberthol          #+#    #+#             */
/*   Updated: 2023/11/10 13:50:20 by gberthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static size_t	calc_dst_size(char *dst, size_t size)
{
	size_t	res;

	res = 0;
	while (dst[res] && res < size)
		res++;
	return (res);
}

int	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	v;
	size_t	i;
	size_t	j;
	size_t	res;

	v = 0;
	while (src[v])
		v++;
	i = 0;
	j = 0;
	while (dst[i])
		i++;
	res = calc_dst_size(dst, size);
	if (size == 0)
		return (v + res);
	while (src[j] && i + j < size - 1)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = 0;
	return (v + res);
}

/*
#include <bsd/string.h>
#include <stdio.h>
int main(void)
{
	char pas[] = "ici";
	char teque[34] = "literalement ";
	char teque2[34] = "literalement ";
	int	result;

	result = ft_strlcat(teque, pas, 5);
	printf("%s, %d\n", teque, result);
	result = strlcat(teque2, pas, 5);
	printf("%s, %d\n", teque2, result);
}
*/
