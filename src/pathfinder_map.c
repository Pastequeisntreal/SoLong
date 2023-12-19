/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gberthol <gberthol@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:59:31 by gberthol          #+#    #+#             */
/*   Updated: 2023/12/08 17:59:31 by gberthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	transform_around(char c, int *collectible)
{
	if (c != '0' && c != 'C')
		return (c);
	if (c == 'C')
		*collectible -= 1;
	return ('2');
}

static void	change_around(char **map, int *collectible, int x, int y)
{
	map[y][x - 1] = transform_around(map[y][x - 1], collectible);
	map[y][x + 1] = transform_around(map[y][x + 1], collectible);
	map[y + 1][x] = transform_around(map[y + 1][x], collectible);
	map[y - 1][x] = transform_around(map[y - 1][x], collectible);
}

static int	check_around(char **map, int y, int x, int *collectible)
{
	int	change;

	if (map[y][x] != '0' && map[y][x] != 'E' && map[y][x] != 'C')
		return (1);
	if (map[y - 1][x] != '2' && map[y + 1][x] != '2'
		&& map[y][x - 1] != '2' && map[y][x + 1] != '2'
		&& map[y - 1][x] != 'P' && map[y + 1][x] != 'P'
		&& map[y][x - 1] != 'P' && map[y][x + 1] != 'P')
		return (1);
	if (map[y][x] == 'E' && !*collectible)
		return (2);
	if (map[y][x] == 'C')
		*collectible -= 1;
	if (map[y][x] != 'E')
		map[y][x] = '2';
	change = 1;
	if (map[y][x - 1] != '2' || map[y][x + 1] != '2'
		|| map[y - 1][x] != '2' || map[y + 1][x] != '2')
		change = 0;
	change_around(map, collectible, x, y);
	if (map[y][x] == 'E')
		return (change);
	return (0);
}

static int	calc_path(char **map, int y, int x, int collectible)
{
	int	change;
	int	result;

	change = 1;
	result = 0;
	while (change)
	{
		change = 0;
		y = 1;
		while (map[y])
		{
			x = 1;
			while (map[y][x])
			{
				result = check_around(map, y, x, &collectible);
				if (result == 2)
					return (0);
				if (!result)
					change = 1;
				x++;
			}
			y++;
		}
	}
	return (1);
}

int	pathfinder_map(char **map)
{
	size_t	coor[2];
	int		find[3];

	coor[0] = 0;
	find[0] = 0;
	find[1] = 0;
	find[2] = 0;
	while (map[coor[0]])
	{
		coor[1] = 0;
		while (map[coor[0]][coor[1]])
		{
			if (map[coor[0]][coor[1]] == 'P')
				find[0]++;
			if (map[coor[0]][coor[1]] == 'E')
				find[1]++;
			if (map[coor[0]][coor[1]] == 'C')
				find[2]++;
			coor[1]++;
		}
		coor[0]++;
	}
	if (find[0] != 1 || find[1] != 1 || find[2] < 1)
		return (1);
	return (calc_path(map, coor[0], coor[1], find[2]));
}
