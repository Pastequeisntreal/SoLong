/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gberthol <gberthol@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:38:28 by gberthol          #+#    #+#             */
/*   Updated: 2023/12/15 13:38:28 by gberthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stddef.h>
#include "mlx.h"
#include "libft.h"

static void	display_sprite(t_sprite *sprites, void *sprite, int x, int y)
{
	mlx_put_image_to_window(sprites->mlx, sprites->win,
		sprite, x * TILE_WIDTH, y * TILE_HEIGHT);
}

static void	display_map(t_sprite *sprite)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (sprite->map[y])
	{
		x = 0;
		while (sprite->map[y][x] && sprite->map[y][x] != '\n')
		{
			if (x % 7 == 0 && sprite->map[y][x] != '1')
				display_sprite(sprite, sprite->tile3, x, y);
			else if (x % 4 == 0 && sprite->map[y][x] != '1')
				display_sprite(sprite, sprite->tile2, x, y);
			else if (sprite->map[y][x] != '1')
				display_sprite(sprite, sprite->tile1, x, y);
			else
				display_sprite(sprite, sprite->wall, x, y);
			if (sprite->map[y][x] == 'C')
				display_sprite(sprite, sprite->collec, x, y);
			if (sprite->map[y][x] == 'E')
				display_sprite(sprite, sprite->exit, x, y);
			x++;
		}
		y++;
	}
}

static int	change_frame(int actual, int new)
{
	actual += new;
	if (actual > 1)
		actual = 0;
	return (actual);
}

static void	display_animated(t_sprite *sprite, int monster_new, int player_new)
{
	size_t		x;
	size_t		y;
	static int	monster_frame = 0;
	static int	player_frame = 0;

	y = 0;
	monster_frame = change_frame(monster_frame, monster_new);
	player_frame = change_frame(player_frame, player_new);
	while (sprite->map[y])
	{
		x = 0;
		while (sprite->map[y][x])
		{
			if (sprite->map[y][x] == 'P' && !player_frame)
				display_sprite(sprite, sprite->character1, x, y);
			else if (sprite->map[y][x] == 'P')
				display_sprite(sprite, sprite->character2, x, y);
			if (sprite->map[y][x] == 'M' && !monster_frame)
				display_sprite(sprite, sprite->monster1, x, y);
			else if (sprite->map[y][x] == 'M')
				display_sprite(sprite, sprite->monster2, x, y);
			x++;
		}
		y++;
	}
}

int	display_screen(t_sprite *sprite)
{
	static int	a = 1;

	display_map(sprite);
	if (!(a % 1000))
		display_animated(sprite, 0, 1);
	else if (!(a % 1200))
	{
		display_animated(sprite, 1, 0);
		a = 0;
	}
	else
		display_animated(sprite, 0, 0);
	a++;
	return (0);
}
