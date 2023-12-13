/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gberthol <gberthol@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:26:21 by gberthol          #+#    #+#             */
/*   Updated: 2023/12/04 15:47:32 by gberthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include "libft.h"

static void	kill_buff(char *buff, char end)
{
	size_t	i;
	size_t	save;

	i = 0;
	while (buff[i] && buff[i] != end)
		i++;
	if (buff[i] == end)
		i += 1;
	save = i;
	while (buff[i])
	{
		buff[i - save] = buff[i];
		i++;
	}
	buff[i - save] = 0;
}

static char	*check_existing(char *result, char *buff, char end, int fd)
{
	ssize_t	readed;

	if (!result)
		result = ft_strenddup(buff, end);
	if (!result)
		return (NULL);
	readed = 1;
	while (result && result[ft_strlen(result) - 1] != end && readed)
	{
		readed = read(fd, buff, BUFFER_SIZE);
		if (readed < 0)
			return (buff[0] = 0, free(result), NULL);
		buff[readed] = 0;
		result = ft_strenddupcat(result, buff, end);
	}
	return (result);
}

char	*get_next_line(int fd)
{
	static char	buff[1024][BUFFER_SIZE + 1] = {0};
	ssize_t		end_with_zero;
	char		*result;

	result = NULL;
	if (fd < 0)
		return (NULL);
	if (!buff[fd][0])
	{
		end_with_zero = read(fd, buff[fd], BUFFER_SIZE);
		if (end_with_zero <= 0)
			return (buff[fd][0] = 0, NULL);
		buff[fd][end_with_zero] = 0;
	}
	result = check_existing(result, buff[fd], '\n', fd);
	if (!result)
		return (NULL);
	kill_buff(buff[fd], '\n');
	return (result);
}
