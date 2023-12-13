/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gberthol <gberthol@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:36:08 by gberthol          #+#    #+#             */
/*   Updated: 2023/11/16 15:36:08 by gberthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include <stddef.h>

void	ft_puthexa_fd(unsigned int nb, int fd, t_alpha_type alpha_type)
{
	char	c;

	if (nb >= 16)
		ft_puthexa_fd(nb / 16, fd, alpha_type);
	if (nb % 16 >= 10)
		c = nb % 16 - 10 + 'A' + alpha_type;
	else
		c = nb % 16 + '0';
	write(fd, &c, 1);
}

void	ft_putmem_fd(unsigned long nb, int fd)
{
	char	c;

	if (nb >= 16)
		ft_putmem_fd(nb / 16, fd);
	if (nb % 16 >= 10)
		c = nb % 16 - 10 + 'a';
	else
		c = nb % 16 + '0';
	write(fd, &c, 1);
}

void	p_option(unsigned long nb, int fd)
{
	if (!nb)
		return (write(fd, "(nil)", 5), (void)0);
	write(fd, "0x", 2);
	ft_putmem_fd(nb, fd);
}
