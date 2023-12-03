/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:02:56 by ketrevis          #+#    #+#             */
/*   Updated: 2023/12/03 17:11:29 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "mlx.h"
#include "so_long.h"

void	pick_texture(char c, int i, int j, t_game *game)
{
	draw_floor(game, j, i);
	if (c == '1')
		draw_wall(game, j, i);
	else if (c == 'C')
		draw_key(game, j, i);
	else if (c == 'P')
	{
		draw_player(game, j, i);
		game->player.x = j;
		game->player.y = i;
	}
	else if (c == 'E')
		draw_exit(game, j, i);
}

void	draw_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			pick_texture(game->map[i][j], i * 32, j * 32, game);
			j++;
		}
		i++;
	}
	mlx_do_sync(game->mlx);
}
