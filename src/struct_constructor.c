/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_constructor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gberthol <gberthol@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:56:38 by gberthol          #+#    #+#             */
/*   Updated: 2023/12/14 11:56:38 by gberthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include "mlx.h"
#include "get_next_line.h"
#include <stdlib.h>

static	t_hero	*get_pos(char **map, t_hero *chara)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				chara->POS.y = y;
				chara->POS.x = x;
			}
			if (map[y][x] == 'C')
				chara->collect += 1;
			x++;
		}
		y++;
	}
	return (chara);
}

t_hero	*hero_constructor(char **map, void *mlx)
{
	t_hero		*chara;

	chara = malloc(sizeof(t_hero));
	if (!chara)
		return (NULL);
	chara->collect = 0;
	chara->move = 0;
	chara->map = map;
	chara->save_tile = '0';
	chara->end_game = 0;
	chara->mlx = mlx;
	return (get_pos(map, chara));
}

static void	*create_image(char *path, void *mlx_ptr)
{
	void	*img;
	int		a;
	int		b;

	img = mlx_xpm_file_to_image(mlx_ptr, path, &a, &b);
	if (!img)
	{
		ft_fprintf(2, "Error: to create %s image", path);
		exit(0);
	}
	return (img);
}

t_sprite	*sprite_constructor(char **map, void *mlx_ptr, void *win)
{
	t_sprite	*sprite;

	sprite = malloc(sizeof(t_sprite));
	if (!sprite)
		return (NULL);
	sprite->tile1 = create_image("rsrc/tile1.xpm", mlx_ptr);
	sprite->tile2 = create_image("rsrc/tile2.xpm", mlx_ptr);
	sprite->tile3 = create_image("rsrc/tile2.xpm", mlx_ptr);
	sprite->character1 = create_image("rsrc/watermelon1.xpm", mlx_ptr);
	sprite->character2 = create_image("rsrc/watermelon2.xpm", mlx_ptr);
	sprite->wall = create_image("rsrc/wall.xpm", mlx_ptr);
	sprite->monster1 = create_image("rsrc/duck1.xpm", mlx_ptr);
	sprite->monster2 = create_image("rsrc/duck2.xpm", mlx_ptr);
	sprite->collec = create_image("rsrc/popo.xpm", mlx_ptr);
	sprite->exit = create_image("rsrc/door.xpm", mlx_ptr);
	sprite->map = map;
	sprite->win = win;
	sprite->mlx = mlx_ptr;
	return (sprite);
}

void	sprite_destructor(t_sprite *sprite)
{
	mlx_destroy_image(sprite->mlx, sprite->tile1);
	mlx_destroy_image(sprite->mlx, sprite->tile2);
	mlx_destroy_image(sprite->mlx, sprite->tile3);
	mlx_destroy_image(sprite->mlx, sprite->character1);
	mlx_destroy_image(sprite->mlx, sprite->character2);
	mlx_destroy_image(sprite->mlx, sprite->wall);
	mlx_destroy_image(sprite->mlx, sprite->monster1);
	mlx_destroy_image(sprite->mlx, sprite->monster2);
	mlx_destroy_image(sprite->mlx, sprite->exit);
	mlx_destroy_image(sprite->mlx, sprite->collec);
	mlx_destroy_window(sprite->mlx, sprite->win);
	mlx_destroy_display(sprite->mlx);
	free(sprite->mlx);
	free(sprite);
}
