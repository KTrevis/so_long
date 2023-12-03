/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:02:56 by ketrevis          #+#    #+#             */
/*   Updated: 2023/12/03 16:06:51 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "mlx.h"
#include "so_long.h"

void	pick_texture(char c, int i, int j, t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->window, game->img.floor, j * 32, i * 32);
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->window, game->img.wall, j * 32, i * 32);
	else if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->window, game->img.key, j * 32, i * 32);
	else if (c == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->window, game->img.player, j * 32, i * 32);
		game->player.x = j * 32;
		game->player.y = i * 32;
	}
	else if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->window, game->img.exit, j * 32, i * 32);
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
			pick_texture(game->map[i][j], i, j, game);
			j++;
		}
		i++;
	}
	mlx_do_sync(game->mlx);
}
