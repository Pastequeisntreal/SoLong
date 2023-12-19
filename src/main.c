/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gberthol <gberthol@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:51:16 by gberthol          #+#    #+#             */
/*   Updated: 2023/11/27 14:08:57 by gberthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include "get_next_line.h"
#include <stdlib.h>

static int	ft_derror_main(int status)
{
	ft_putstr_fd("Error\n", 2);
	if (status == 1)
		ft_putstr_fd("You need a parameter as 'map_name'.ber", 2);
	if (status == 2)
		ft_putstr_fd("Map need to be a .ber file", 2);
	ft_putchar_fd('\n', 2);
	return (1);
}

int	main(int argc, char **argv)
{
	char	**result;

	if (argc != 2)
		return (ft_derror_main(1));
	if (!ft_strnstr(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 6))
		return (ft_derror_main(2));
	result = get_file(argv[1]);
	check_map(result);
	init_game(result);
	free_map(result);
}
