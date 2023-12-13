/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gberthol <gberthol@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:31:56 by gberthol          #+#    #+#             */
/*   Updated: 2023/12/04 14:55:18 by gberthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

void	ft_put_all_u(unsigned int content, char c, int fd)
{
	if (c == 'u')
		ft_putunbr_fd(content, fd);
	if (c == 'x')
		ft_puthexa_fd(content, fd, LOWER);
	if (c == 'X')
		ft_puthexa_fd(content, fd, CAPITALIZE);
}

void	get_flag(va_list var, char c, int fd)
{
	if (c == 'c')
		ft_putchar_fd((unsigned char)va_arg(var, int), fd);
	else if (c == 's')
		ft_putstr_fd(va_arg(var, char *), fd);
	else if (c == 'd' || c == 'i')
		ft_putnbr_fd(va_arg(var, int), fd);
	else if (c == 'x' || c == 'u' || c == 'X')
		ft_put_all_u(va_arg(var, unsigned int), c, fd);
	else if (c == 'p')
		p_option(va_arg(var, unsigned long), fd);
	else if (c == '%')
		ft_putchar_fd('%', fd);
}

void	ft_fprintf(int fd, const char *str, ...)
{
	size_t	i;
	va_list	var;

	if (!str || !str[0])
		return ;
	i = 0;
	va_start(var, str);
	while (str[i])
	{
		if (str[i] == '%')
			get_flag(var, str[++i], fd);
		else
			ft_putchar_fd(str[i], fd);
		i++;
	}
	va_end(var);
}

void	ft_printf(const char *str, ...)
{
	size_t	i;
	va_list	var;

	if (!str || !str[0])
		return ;
	i = 0;
	va_start(var, str);
	while (str[i])
	{
		if (str[i] == '%')
			get_flag(var, str[++i], 1);
		else
			ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(var);
}
