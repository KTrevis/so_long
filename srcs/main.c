/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:33:26 by ketrevis          #+#    #+#             */
/*   Updated: 2023/12/02 13:00:22 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	quit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}

int	handle_input(int keycode, t_game *game)
{
	(void)game;
	if (keycode == KEY_ESC)
		quit_game(game);
	return (0);
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, 1920 / 2, 1080 / 2, "");
	mlx_hook(game->window, KeyPress, KeyPressMask, handle_input, game);
	mlx_loop(game->mlx);
}

int	main(void)
{
	t_game	game;

	init_game(&game);
}
