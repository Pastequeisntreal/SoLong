/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_chara.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gberthol <gberthol@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:09:38 by gberthol          #+#    #+#             */
/*   Updated: 2023/12/11 17:09:38 by gberthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

void	move_char(t_hero *chara, int y, int x)
{
	char	save;

	save = chara->map[chara->POS->y + y][chara->POS->x + x];
	if (save != '1')
	{
		if (save == 'C')
		{
			chara->collectible -= 1;
			save = '0';
		}
		if (save == 'M')
			chara->position.x = 0;
		chara->map[chara->POS->y + y][chara->POS->x + x] = 'P';
		chara->map[chara->POS->y][chara->POS->x] = chara->save_tile;
		chara->save_tile = save;
	}
}

int	check_end(t_hero *chara, int max_collectible)
{
	if (chara->save_tile == 'E' && chara->collectible == 0)
	{
		ft_printf("Victory !\n");
		return (1);
	}
	else if (chara->position.x == 0)
	{
		ft_printf("Defeat !\n");
		return (1);
	}
	return (0);
}
