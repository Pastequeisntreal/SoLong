/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gberthol <gberthol@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:33:34 by gberthol          #+#    #+#             */
/*   Updated: 2023/11/16 15:33:34 by gberthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putunbr_fd(unsigned int nb, int fd)
{
	char	c;

	if (nb >= 10)
		ft_putunbr_fd(nb / 10, fd);
	c = nb % 10 + '0';
	write(fd, &c, 1);
}
