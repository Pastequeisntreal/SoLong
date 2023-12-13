/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gberthol <gberthol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:26:15 by gberthol          #+#    #+#             */
/*   Updated: 2023/11/13 09:56:10 by gberthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;
	size_t	i;

	if ((nmemb > nmemb * size || size > nmemb * size) && size && nmemb)
		return (NULL);
	res = malloc(nmemb * size);
	if (!res)
		return (NULL);
	if (nmemb == 0 || size == 0)
		return (res);
	i = 0;
	while (i < nmemb * size)
	{
		((char *)res)[i] = 0;
		i++;
	}
	return (res);
}

/*
#include <stdio.h>
int main(void)
{
	int	*pasteque;

	pasteque = ft_calloc(3, sizeof(int));
	pasteque[0] = 4;
	pasteque[1] = 2;
	pasteque[2] = 0;
	for (int i = 0; i < 3; i++)
		printf("%d", pasteque[i]);
	free(pasteque);
	return 0;
}
*/
