/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gberthol <gberthol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:18:51 by gberthol          #+#    #+#             */
/*   Updated: 2023/11/09 13:50:32 by gberthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}

/*
#include <unistd.h>
void	ft_putchar(unsigned int i, char *c)
{
	i = 0;
	write(1, c, 1);
}

int main(int argc, char **argv)
{
	argc = 0;
	ft_striteri(argv[1], &ft_putchar);
}
*/
