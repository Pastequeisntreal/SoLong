/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gberthol <gberthol@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:00:54 by gberthol          #+#    #+#             */
/*   Updated: 2023/12/05 15:00:54 by gberthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "libft.h"
#include "get_next_line.h"
#include "so_long.h"

size_t	ft_cstrlen(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static void	error_func(char **map)
{
	size_t	i;

	i = 0;
	ft_fprintf(2, "Error\nmap design isn't right\n");
	free_map(map);
	exit(0);
}

void	check_lines(char **map, size_t last_c)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		if (ft_cstrlen(map[i], '\n') != last_c + 1)
			error_func(map);
		if (map[i][0] != '1' || map[i][last_c] != '1')
			error_func(map);
		i++;
	}
}

void	check_inside_map_char(char **map)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] && map[y][x] != '\n')
		{
			if (map[y][x] != '1' && map[y][x] != '0' && map[y][x] != 'C'
				&& map[y][x] != 'P' && map[y][x] != 'M' && map[y][x] != 'E')
				error_func(map);
			x++;
		}
		y++;
	}
}

void	check_map(char **map)
{
	size_t	last_c;
	size_t	nbr_line;

	last_c = 0;
	nbr_line = 0;
	while (map[nbr_line])
		nbr_line++;
	if (nbr_line == 1)
		error_func(map);
	while (map[0][last_c + 1] && map[0][last_c + 1] != '\n'
		&& map[0][last_c] == '1' &&
		map[nbr_line - 1][last_c] == '1')
		last_c++;
	if (map[0][last_c + 2] || map[0][last_c] != map[nbr_line - 1][last_c])
		error_func(map);
	check_lines(map, last_c);
	check_inside_map_char(map);
	if (is_map_solutionable(map))
		error_func(map);
}
