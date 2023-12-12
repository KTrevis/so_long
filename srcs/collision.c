/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:16:44 by ketrevis          #+#    #+#             */
/*   Updated: 2023/12/12 18:09:32 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
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
	}
}

void	move_enemy(t_game *game, t_enemy *enemy)
{
	t_coords	old_coords;

	old_coords.x = enemy->x;
	old_coords.y = enemy->y;
	game->map[enemy->y / 32][enemy->x / 32] = '0';
	for (int i = 0; game->map[i]; i++)
		ft_printf("%s\n", game->map[i]);
	if (enemy->orientation == 'V')
		enemy->y += 32 * enemy->direction;
	else
		enemy->x += 32 * enemy->direction;
	if (game->map[enemy->y / 32][enemy->x / 32] == '1')
	{
		enemy->x = old_coords.x;
		enemy->y = old_coords.y;
		enemy->direction = -enemy->direction;
	}
	game->map[enemy->y / 32][enemy->x / 32] = enemy->orientation;
	draw_target(game, old_coords.x, old_coords.y, "floor");
	draw_target(game, enemy->x, enemy->y, "enemy");
}

void	enemy_collision(t_game *game)
{
	char	collider;
	int		i;

	i = 0;
	collider = game->map[game->player.y / 32][game->player.x / 32];
	if (collider == 'V' || collider == 'H')
	{
		ft_printf("YOU DIEDED\n");
		quit_game(game);
	}
	while (i < game->nbr_enemies)
	{
		move_enemy(game, &game->enemies[i]);
		i++;
	}
}
