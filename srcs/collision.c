/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:16:44 by ketrevis          #+#    #+#             */
/*   Updated: 2023/12/13 13:45:00 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "so_long.h"

void	wall_collision(t_game *game, t_coords old_coords)
{
	char	collider;

	collider = game->map[game->player.y / IMG_SIZE][game->player.x / IMG_SIZE];
	if (collider != '1')
		ft_printf("%d\n", ++game->player.moves);
	else
	{
		game->player.x = old_coords.x;
		game->player.y = old_coords.y;
	}
}

void	key_collision(t_game *game)
{
	char	collider;

	collider = game->map[game->player.y / IMG_SIZE][game->player.x / IMG_SIZE];
	if (collider == 'C')
	{
		game->map[game->player.y / IMG_SIZE][game->player.x / IMG_SIZE] = '0';
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
	if (enemy->orientation == 'V')
		enemy->y += IMG_SIZE * enemy->direction;
	else
		enemy->x += IMG_SIZE * enemy->direction;
	if (game->map[enemy->y / IMG_SIZE][enemy->x / IMG_SIZE] == '1')
	{
		enemy->x = old_coords.x;
		enemy->y = old_coords.y;
		enemy->direction = -enemy->direction;
	}
	if (game->map[old_coords.y / IMG_SIZE][old_coords.x / IMG_SIZE] == 'C')
		draw_target(game, old_coords.x, old_coords.y, "key");
	else
		draw_target(game, old_coords.x, old_coords.y, "floor");
	draw_target(game, enemy->x, enemy->y, "enemy");
}

void	enemy_collision(t_game *game)
{
	unsigned int		i;

	i = 0;
	while (i < game->nbr_enemies)
	{
		if (game->player.y == game->enemies[i].y
			&& game->player.x == game->enemies[i].x)
		{
			ft_printf("YOU DIEDED");
			quit_game(game);
		}
		move_enemy(game, &game->enemies[i]);
		if (game->player.y == game->enemies[i].y
			&& game->player.x == game->enemies[i].x)
		{
			ft_printf("YOU DIEDED");
			quit_game(game);
		}
		i++;
	}
}
