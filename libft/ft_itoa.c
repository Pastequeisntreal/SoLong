/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gberthol <gberthol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:17:11 by gberthol          #+#    #+#             */
/*   Updated: 2023/11/09 12:31:34 by gberthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	intlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		n += 1;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*rev_str(char *str)
{
	char	save;
	int		i;
	int		size;

	size = 0;
	while (str[size])
		size++;
	i = 0;
	size -= 1;
	while (i < size)
	{
		save = str[i];
		str[i] = str[size];
		str[size] = save;
		size -= 1;
		i++;
	}
	return (str);
}

static void	calc_itoa(char *res, unsigned int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		res[i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	res[i] = 0;
	rev_str(res);
}

char	*ft_itoa(int n)
{
	char	*res;

	res = malloc(sizeof(char) * (intlen(n) + 1));
	if (!res)
		return (NULL);
	if (n < 0)
	{
		res[0] = '-';
		calc_itoa(&res[1], n * -1);
	}
	else if (n > 0)
		calc_itoa(res, n);
	else
	{
		res[0] = '0';
		res[1] = 0;
	}
	return (res);
}
