/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:33:26 by ketrevis          #+#    #+#             */
/*   Updated: 2023/12/02 13:21:38 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, 1920 / 2, 1080 / 2, "");
	mlx_hook(game->window, KeyPress, KeyPressMask, handle_input, game);
	mlx_loop(game->mlx);
}

int	args_invalid(int ac, char **av)
{
	char	*str;
	int	i;

	if (ac < 2)
		return (ft_printf("No map path given as argument."));
	if (ac > 2)
		return (ft_printf("Too many arguments."));
	return (0);
	str = av[1];
	i = 0;
	while (str[i])
	{
		i++;
	}
}

int	main(int ac, char **av)
{
	t_game	game;

	if (args_invalid(ac, av))
		return (0);
	init_game(&game);
}
