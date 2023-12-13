/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gberthol <gberthol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:40:49 by gberthol          #+#    #+#             */
/*   Updated: 2023/11/10 09:47:26 by gberthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	r;

	i = 0;
	r = 0;
	while (src[r])
		r++;
	if (size == 0)
		return (r);
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (size > 0)
		dst[i] = 0;
	return (r);
}

/*
#include <bsd/string.h>
#include <stdio.h>

int main(void)
{
	char pasteque[] = "pasteque";
	char psa[] = "ahhhhhhhhhhhhhhhh";
	char psa2[] = "ahhhhhhhhhhhhhhhh";
	int res2;
	int res;

	res = strlcpy(psa, pasteque, 4);
	res2 = ft_strlcpy(psa2, pasteque, 4);
	printf("lib [%s | %d]\n", psa, res);
	printf("mine [%s | %d]\n", psa2, res2);
}
*/
