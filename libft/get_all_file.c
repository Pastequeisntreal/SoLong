/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gberthol <gberthol@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:52:06 by gberthol          #+#    #+#             */
/*   Updated: 2023/12/08 15:52:06 by gberthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static void	derror_file(char *path, char **result, int status)
{
	size_t	i;

	i = 0;
	if (!status)
		ft_fprintf(2, "Error\n%s no such file or empty file\n", path);
	if (status == 1)
		ft_fprintf(2, "Error\nto malloc result\n");
	if (status == 2)
	{
		ft_fprintf(2, "Error\nto malloc result[i]\n");
		while (result[i])
		{
			free(result[i]);
			i++;
		}
		free(result);
	}
	exit(0);
}

char	**get_file(char *path)
{
	size_t	size;
	char	**result;
	int		fd;
	size_t	i;

	size = ft_linelen(path);
	if (!size)
		derror_file(path, NULL, 0);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		derror_file(path, NULL, 0);
	result = ft_calloc(size + 1, sizeof(char *));
	if (!result)
		derror_file(NULL, NULL, 1);
	i = 0;
	while (i < size)
	{
		result[i] = get_next_line(fd);
		if (!result[i])
			derror_file(NULL, result, 2);
		i++;
	}
	close(fd);
	return (result);
}
