/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:33:26 by ketrevis          #+#    #+#             */
/*   Updated: 2023/12/03 17:28:48 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "mlx.h"
#include "so_long.h"

static void	init_game(t_game *game)
{
	int	x;

	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, ft_strlen(game->map[0]) * 32,
			map_height(game->map) * 32, "");
	game->img.wall = mlx_xpm_file_to_image(
			game->mlx, "assets/wall.xpm", &x, &x);
	game->img.floor = mlx_xpm_file_to_image(
			game->mlx, "assets/floor.xpm", &x, &x);
	game->img.player = mlx_xpm_file_to_image(
			game->mlx, "assets/player.xpm", &x, &x);
	game->img.key = mlx_xpm_file_to_image(
			game->mlx, "assets/key.xpm", &x, &x);
	game->img.exit = mlx_xpm_file_to_image(
			game->mlx, "assets/exit.xpm", &x, &x);
	game->player.keys = 0;
	game->player.moves = 0;
	draw_map(game);
	mlx_hook(game->window, KeyPress, KeyPressMask, handle_input, game);
	mlx_loop(game->mlx);
}

static int	map_extension_invalid(char *path)
{
	int	i;

	i = ft_strlen(path) - 1;
	while (i >= 0 && path[i] != '.')
		i--;
	return (ft_strncmp(".ber", path + i, ft_strlen(path + i)));
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

	if (args_invalid(ac, av) || !parse_map(av[1], &game))
		return (0);
	init_game(&game);
}
