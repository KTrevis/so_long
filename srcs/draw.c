/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:04:31 by ketrevis          #+#    #+#             */
/*   Updated: 2023/12/03 17:07:46 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

void	draw_player(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, game->img.player, x, y);
}

void	draw_floor(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, game->img.floor, x, y);
}

void	draw_wall(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, game->img.wall, x, y);
}

void	draw_key(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, game->img.key, x, y);
}

void	draw_exit(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, game->img.exit, x, y);
}
