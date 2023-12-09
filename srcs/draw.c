/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:04:31 by ketrevis          #+#    #+#             */
/*   Updated: 2023/12/09 13:37:04 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "mlx.h"
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
}
