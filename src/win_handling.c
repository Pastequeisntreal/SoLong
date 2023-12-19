/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gberthol <gberthol@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:33:07 by gberthol          #+#    #+#             */
/*   Updated: 2023/12/18 15:33:07 by gberthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

void	display_end(t_hero *chara)
{
	if (chara->end_game == 1)
		ft_printf("Victory !\n");
	else if (chara->end_game == 2)
		ft_printf("Defeat !\n");
	else
		ft_printf("Your game as been interrupted!\n");
}
