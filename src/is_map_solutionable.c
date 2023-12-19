/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_solutionable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gberthol <gberthol@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:51:07 by gberthol          #+#    #+#             */
/*   Updated: 2023/12/19 10:51:07 by gberthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"
#include <stdlib.h>

int	is_map_solutionable(char **map)
{
	int		res;
	char	**cpy;

	cpy = doublearrdup(map);
	if (!cpy)
	{
		ft_putstr_fd("Error: malloc can't allocate memory", 2);
		exit(1);
	}
	res = pathfinder_map(cpy);
	free_map(cpy);
	return (res);
}
