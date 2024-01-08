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
#include "mlx.h"
#include <stdlib.h>

void	print_move(t_hero *chara)
{
	char	*message;

	chara->move++;
	ft_printf("%d\n", chara->move);
	message = ft_itoa(chara->move);
	if (!message)
		return (chara->end_game = 3, (void)0);
	mlx_clear_window(chara->mlx, chara->win);
	mlx_string_put(chara->mlx, chara->win, 16,
		(int)ft_nbrline(chara->map) * 32 + 10, 16777215, message);
}

void	move_chara(t_hero *chara, int y, int x)
{
	char	save;

	save = chara->map[chara->POS.y + y][chara->POS.x + x];
	if (save != '1')
	{
		if (save == 'M')
		{
			chara->end_game = 2;
			return ;
		}
		if (save == 'C')
		{
			chara->collect -= 1;
			save = '0';
		}
		chara->map[chara->POS.y + y][chara->POS.x + x] = 'P';
		chara->map[chara->POS.y][chara->POS.x] = chara->save_tile;
		chara->save_tile = save;
		chara->POS.y += y;
		chara->POS.x += x;
		print_move(chara);
	}
	if (chara->save_tile == 'E' && chara->collect == 0)
		chara->end_game = 1;
}
