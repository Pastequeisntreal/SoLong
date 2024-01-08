/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gberthol <gberthol@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:32:41 by gberthol          #+#    #+#             */
/*   Updated: 2023/12/08 12:32:41 by gberthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stddef.h>

typedef struct s_vector2i
{
	size_t	x;
	size_t	y;
}	t_vector2i;

typedef struct s_hero
{
	size_t		collect;
	size_t		move;
	char		**map;
	t_vector2i	position;
	char		save_tile;
	int			end_game;
	void		*mlx;
	void		*win;
}	t_hero;

# define POS position

typedef struct s_sprite
{
	void	*tile1;
	void	*tile2;
	void	*tile3;
	void	*character1;
	void	*character2;
	void	*collec;
	void	*wall;
	void	*monster1;
	void	*monster2;
	void	*exit;
	char	**map;
	void	*win;
	void	*mlx;
}	t_sprite;

# define TILE_HEIGHT 32
# define TILE_WIDTH 32

void		init_game(char **map);
void		check_map(char **map);
void		free_map(char **map);
void		display_end(t_hero *chara);
void		move_chara(t_hero *chara, int y, int x);
void		sprite_destructor(t_sprite *sprite);

int			display_screen(t_sprite *sprite);
int			is_map_solutionable(char **map);
int			pathfinder_map(char **map);

char		**doublearrdup(char **tab);

t_hero		*hero_constructor(char **map, void *mlx, void *win);
t_sprite	*sprite_constructor(char **map, void *mlx_ptr, void *win);

#endif
