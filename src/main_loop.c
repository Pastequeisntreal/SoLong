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
#include "libft.h"
#include <stdlib.h>

int	get_event(int key_code, t_hero *params)
{
	if (key_code == 'w')
		move_chara(params, -1, 0);
	if (key_code == 's')
		move_chara(params, 1, 0);
	if (key_code == 'a')
		move_chara(params, 0, -1);
	if (key_code == 'd')
		move_chara(params, 0, 1);
	if (key_code == 65307 || params->end_game)
		mlx_loop_end(params->mlx);
	return (0);
}

int	close_event(void *suppr)
{
	mlx_loop_end(suppr);
	return (0);
}

void	game_loop(void *mlx_ptr, void *win, t_hero *chara)
{
	t_sprite	*sprites;

	sprites = sprite_constructor(chara->map, mlx_ptr, win);
	mlx_key_hook(win, get_event, chara);
	mlx_loop_hook(mlx_ptr, display_screen, sprites);
	mlx_hook(win, 17, 0, close_event, mlx_ptr);
	mlx_loop(mlx_ptr);
	display_end(chara);
	sprite_destructor(sprites);
}

void	init_game(char **map)
{
	void	*mlx;
	void	*win;
	t_hero	*chara;

	mlx = mlx_init();
	chara = hero_constructor(map, mlx);
	if (!chara)
	{
		ft_printf("Error: malloc the character struct");
		free_map(map);
		exit(0);
	}
	win = mlx_new_window(mlx, (ft_strlen(map[0]) - 1) * 32,
			ft_nbrline(map) * 32, "Pasteque");
	mlx_set_font(mlx, win, "rsrc/Daydream.ttf");
	game_loop(mlx, win, chara);
	free(chara);
}
