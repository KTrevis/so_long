/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:01:07 by ketrevis          #+#    #+#             */
/*   Updated: 2023/12/13 12:32:05 by ketrevis         ###   ########.fr       */
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
	free(game->enemies);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free_split(game->map);
	free(game->mlx);
	exit(0);
}

int	move_player(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		quit_game(game);
	else if (keycode == KEY_W)
		game->player.y -= IMG_SIZE;
	else if (keycode == KEY_S)
		game->player.y += IMG_SIZE;
	else if (keycode == KEY_A)
		game->player.x -= IMG_SIZE;
	else if (keycode == KEY_D)
		game->player.x += IMG_SIZE;
	else
		return (0);
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
		x += IMG_SIZE;
		i++;
	}
	free(str);
}

int	handle_input(int keycode, t_game *game)
{
	t_coords	old_coords;

	old_coords.x = game->player.x;
	old_coords.y = game->player.y;
	if (!move_player(keycode, game))
		return (0);
	wall_collision(game, old_coords);
	key_collision(game);
	draw_target(game, old_coords.x, old_coords.y, "floor");
	if (BONUS)
	{
		enemy_collision(game);
		display_moves(game);
	}
	if (game->map[old_coords.y / IMG_SIZE][old_coords.x / IMG_SIZE] == 'E')
		draw_target(game, old_coords.x, old_coords.y, "exit");
	draw_target(game, game->player.x, game->player.y, "player");
	return (0);
}
