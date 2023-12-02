/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:33:26 by ketrevis          #+#    #+#             */
/*   Updated: 2023/12/02 15:49:16 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "so_long.h"
#include <stdio.h>

static void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, 1920 / 2, 1080 / 2, "");
	mlx_hook(game->window, KeyPress, KeyPressMask, handle_input, game);
	mlx_loop(game->mlx);
}

static int	map_extension_invalid(char *path)
{
	int	i;

	i = ft_strlen(path) - 1;
	while (i >= 0 && path[i] != '.')
		i--;
	return (ft_strncmp(".ber", path + i, 4));
}

static int	args_invalid(int ac, char **av)
{
	if (ac < 2)
	{
		printf("Error.\nNo path given as argument");
		return (1);
	}
	if (ac > 2)
	{
		printf("Error.\nToo many arguments");
		return (1);
	}
	if (map_extension_invalid(av[1]))
	{
		printf("Error.\nMap extension invalid");
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (args_invalid(ac, av))
		return (0);	
	parse_map(av[1]);
	init_game(&game);
}
