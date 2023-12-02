/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:33:26 by ketrevis          #+#    #+#             */
/*   Updated: 2023/12/02 13:56:26 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "so_long.h"

static void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, 1920 / 2, 1080 / 2, "");
	mlx_hook(game->window, KeyPress, KeyPressMask, handle_input, game);
	mlx_loop(game->mlx);
}

static int	map_extension_invalid(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (i >= 0 && str[i] != '.')
		i--;
	return (ft_strncmp(".ber", str + i, 4));
}

static int	args_invalid(int ac, char **av)
{
	if (ac < 2)
		return (ft_printf("No map path given as argument."));
	if (ac > 2)
		return (ft_printf("Too many arguments."));
	if (map_extension_invalid(av[1]))
		return (ft_printf("Map extension invalid"));
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (args_invalid(ac, av))
		return (0);
	init_game(&game);
}
