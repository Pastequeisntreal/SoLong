/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gberthol <gberthol@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:13:24 by gberthol          #+#    #+#             */
/*   Updated: 2023/12/08 12:13:24 by gberthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include <stdlib.h>

t_hero	*hero_constructor(char **map)
{
	t_hero		*chara;
	int			x;
	int			y;

	chara = malloc(sizeof(t_hero));
	if (!chara)
		return (NULL);
	chara->collect = 0;
	chara->move = 0;
	chara->map = map;
	chara->save_tile = '0';
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] && map[y][x] == 'P')
		{
			if (map[y][x] == 'P')
			{
				chara->position.y = y;
				chara->position.x = x;
			}
			if (map[y][x] == 'C')
				chara->collect += 1;
			x++;
		}
		y++;
	}
	return (chara);
}

void	game_loop(void *mlx_ptr, void *win, t_hero *chara)
{

}

void	init_game(char **map)
{
	void	*mlx_ptr;
	void	*win;
	t_hero	*chara;

	chara = hero_constructor(map);
	mlx_ptr = mlx_init();
	win = mlx_new_window(mlx_ptr, 300, 300, "Pasteque");
	game_loop(mlx_ptr, win, chara);
}
