/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:02:56 by ketrevis          #+#    #+#             */
/*   Updated: 2023/12/13 11:55:57 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_target(t_game *game, int x, int y, char *target)
{
	if (!ft_strcmp(target, "player"))
		mlx_put_image_to_window(
			game->mlx, game->window, game->img.player, x, y);
	else if (!ft_strcmp(target, "floor"))
		mlx_put_image_to_window(game->mlx, game->window, game->img.floor, x, y);
	else if (!ft_strcmp(target, "wall"))
		mlx_put_image_to_window(game->mlx, game->window, game->img.wall, x, y);
	else if (!ft_strcmp(target, "key"))
		mlx_put_image_to_window(game->mlx, game->window, game->img.key, x, y);
	else if (!ft_strcmp(target, "exit"))
		mlx_put_image_to_window(game->mlx, game->window, game->img.exit, x, y);
	else if (!ft_strcmp(target, "enemy"))
		mlx_put_image_to_window(game->mlx, game->window, game->img.enemy, x, y);
}

void	pick_texture(char c, int i, int j, t_game *game)
{
	draw_target(game, j, i, "floor");
	if (c == '1')
		draw_target(game, j, i, "wall");
	else if (c == 'C')
		draw_target(game, j, i, "key");
	else if (c == 'P')
	{
		draw_target(game, j, i, "player");
		game->player.x = j;
		game->player.y = i;
	}
	else if (c == 'E')
		draw_target(game, j, i, "exit");
	else if (c == 'V' || c == 'H')
		draw_target(game, j, i, "enemy");
}

void	draw_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			pick_texture(game->map[i][j], i * IMG_SIZE, j * IMG_SIZE, game);
			j++;
		}
		i++;
	}
}
