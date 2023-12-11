/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:01:07 by ketrevis          #+#    #+#             */
/*   Updated: 2023/12/11 17:37:27 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	quit_game(t_game *game)
{
	unsigned int	i;

	i = 0;
	mlx_destroy_image(game->mlx, game->img.wall);
	mlx_destroy_image(game->mlx, game->img.player);
	mlx_destroy_image(game->mlx, game->img.floor);
	mlx_destroy_image(game->mlx, game->img.exit);
	mlx_destroy_image(game->mlx, game->img.key);
	mlx_destroy_image(game->mlx, game->img.enemy);
	while (i <= 9)
		mlx_destroy_image(game->mlx, game->img.numbers[i++]);
	free(game->img.numbers);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free_split(game->map);
	free(game->mlx);
	exit(0);
}

int	handle_key(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		quit_game(game);
	else if (keycode == KEY_W)
		game->player.y -= 32;
	else if (keycode == KEY_S)
		game->player.y += 32;
	else if (keycode == KEY_A)
		game->player.x -= 32;
	else if (keycode == KEY_D)
		game->player.x += 32;
	return (1);
}

void	display_moves(t_game *game)
{
	char	*str;
	int		i;
	int		x;

	x = 0;
	i = 0;
	str = ft_itoa(game->player.moves);
	if (!str)
		return ;
	while (str[i])
	{
		mlx_put_image_to_window(
			game->mlx, game->window, game->img.numbers[str[i] - '0'], x, 0);
		x += 32;
		i++;
	}
	free(str);
}

int	handle_input(int keycode, t_game *game)
{
	int	old_coordinates[2];

	old_coordinates[0] = game->player.x;
	old_coordinates[1] = game->player.y;
	if (!handle_key(keycode, game))
		return (0);
	wall_collision(game, old_coordinates);
	key_collision(game, old_coordinates);
	enemy_collision(game);
	draw_target(game, old_coordinates[0], old_coordinates[1], "floor");
	if (game->map[old_coordinates[1] / 32][old_coordinates[0] / 32] == 'E')
		draw_target(game, old_coordinates[0], old_coordinates[1], "exit");
	draw_target(game, game->player.x, game->player.y, "player");
	display_moves(game);
	return (0);
}
