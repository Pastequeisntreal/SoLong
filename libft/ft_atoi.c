/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gberthol <gberthol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:53:12 by gberthol          #+#    #+#             */
/*   Updated: 2023/11/09 12:22:49 by gberthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_atoi(const char *str)
{
	size_t	i;
	int		result;
	int		sign;

	result = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if ((str[i] == '-' || str[i] == '+') && str[i++])
	{
		if (str[i - 1] == '-')
			sign = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i++] - '0');
	return (result * sign);
}

/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	argc = 0;
	printf("%d\n", ft_atoi(argv[1]));
	return (0);
}
*/
