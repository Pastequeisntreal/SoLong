/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linelen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gberthol <gberthol@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:16:45 by gberthol          #+#    #+#             */
/*   Updated: 2023/12/06 14:16:45 by gberthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stddef.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

size_t	ft_linelen(char *path)
{
	int		fd;
	size_t	len;
	char	*str;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	len = 0;
	str = get_next_line(fd);
	while (str)
	{
		free(str);
		len++;
		str = get_next_line(fd);
	}
	close(fd);
	return (len);
}
