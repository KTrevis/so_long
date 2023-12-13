/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:19:44 by ketrevis          #+#    #+#             */
/*   Updated: 2023/12/13 11:55:57 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

unsigned int	number_of_enemies(t_game *game)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'V' || game->map[i][j] == 'H')
				count++;
			j++;
		}
		i++;
	}
	game->nbr_enemies = count;
	return (count);
}

void	store_enemies(t_game *game)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'V' || game->map[i][j] == 'H')
			{
				game->enemies[k].x = j * IMG_SIZE;
				game->enemies[k].y = i * IMG_SIZE;
				game->enemies[k].direction = 1;
				game->enemies[k].orientation = game->map[i][j];
				k++;
			}
			j++;
		}
		i++;
	}
}

void	load_enemies(t_game *game)
{
	game->enemies = malloc(number_of_enemies(game) * sizeof(t_enemy));
	store_enemies(game);
}
