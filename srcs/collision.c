/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:16:44 by ketrevis          #+#    #+#             */
/*   Updated: 2023/12/11 15:53:42 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wall_collision(t_game *game, int *old_coordinates)
{
	char	collider;

	collider = game->map[game->player.y / 32][game->player.x / 32];
	if (collider != '1')
		ft_printf("%d\n", ++game->player.moves);
	else
	{
		game->player.x = old_coordinates[0];
		game->player.y = old_coordinates[1];
	}
}

void	key_collision(t_game *game, int *old_coordinates)
{
	char	collider;

	collider = game->map[game->player.y / 32][game->player.x / 32];
	if (collider == 'C')
	{
		game->map[game->player.y / 32][game->player.x / 32] = '0';
		game->player.keys++;
	}
	else if (collider == 'E' && game->player.keys == game->max_keys)
	{
		ft_printf("Fini en %d coups\n", game->player.moves);
		quit_game(game);
		exit(0);
	}
}
