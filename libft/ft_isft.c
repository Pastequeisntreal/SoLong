/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gberthol <gberthol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:14:11 by gberthol          #+#    #+#             */
/*   Updated: 2023/11/10 11:15:32 by gberthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int a)
{
	if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))
		return (1);
	return (0);
}

int	ft_isdigit(int a)
{
	if (a >= '0' && a <= '9')
		return (1);
	return (0);
}

int	ft_isalnum(int a)
{
	if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z')
		|| (a >= '0' && a <= '9'))
		return (1);
	return (0);
}

int	ft_isascii(int a)
{
	if (a >= 0 && a <= 127)
		return (1);
	return (0);
}

int	ft_isprint(int a)
{
	if (a >= 32 && a <= 126)
		return (1);
	return (0);
}
