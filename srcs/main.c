/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:33:26 by ketrevis          #+#    #+#             */
/*   Updated: 2023/12/11 12:24:18 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

static void	load_numbers(t_game *game)
{
	int	x;

	game->img.numbers = malloc(10 * sizeof(void *));
	game->img.numbers[0] = mlx_xpm_file_to_image(
			game->mlx, "assets/zero.xpm", &x, &x);
	game->img.numbers[1] = mlx_xpm_file_to_image(
			game->mlx, "assets/one.xpm", &x, &x);
	game->img.numbers[2] = mlx_xpm_file_to_image(
			game->mlx, "assets/two.xpm", &x, &x);
	game->img.numbers[3] = mlx_xpm_file_to_image(
			game->mlx, "assets/three.xpm", &x, &x);
	game->img.numbers[4] = mlx_xpm_file_to_image(
			game->mlx, "assets/four.xpm", &x, &x);
	game->img.numbers[5] = mlx_xpm_file_to_image(
			game->mlx, "assets/five.xpm", &x, &x);
	game->img.numbers[6] = mlx_xpm_file_to_image(
			game->mlx, "assets/six.xpm", &x, &x);
	game->img.numbers[7] = mlx_xpm_file_to_image(
			game->mlx, "assets/seven.xpm", &x, &x);
	game->img.numbers[8] = mlx_xpm_file_to_image(
			game->mlx, "assets/eight.xpm", &x, &x);
	game->img.numbers[9] = mlx_xpm_file_to_image(
			game->mlx, "assets/nine.xpm", &x, &x);
}

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
	game->img.enemy = mlx_xpm_file_to_image(
			game->mlx, "assets/enemy.xpm", &x, &x);
	game->player.keys = 0;
	game->player.moves = 0;
	load_numbers(game);
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
	return (ft_strcmp(".ber", path + i));
}

static int	args_invalid(int ac, char **av)
{
	if (ac < 2)
	{
		ft_printf("Error.\nNo path given as argument\n");
		return (1);
	}
	if (ac > 2)
	{
		ft_printf("Error.\nToo many arguments\n");
		return (1);
	}
	if (map_extension_invalid(av[1]))
	{
		ft_printf("Error.\nMap extension invalid\n");
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (args_invalid(ac, av) || !parse_map(av[1], &game))
		return (0);
	if (impossible_map(av[1], &game))
	{
		printf("Error\nNo valid path");
		return (0);
	}
	init_game(&game);
}
