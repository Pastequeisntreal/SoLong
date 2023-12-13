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
}	t_hero;

# define POS position

void	init_game(char **map);
void	check_map(char **map);
void	free_map(char **map);

int		is_map_solutionable(char **map);

char	**doublearrdup(char **tab);

#endif
