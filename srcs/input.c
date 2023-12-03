/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:01:07 by ketrevis          #+#    #+#             */
/*   Updated: 2023/12/03 16:12:30 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "mlx.h"
#include "so_long.h"

void	quit_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img.wall);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free_split(game->map);
	free(game->mlx);
	exit(0);
}

int	handle_input(int keycode, t_game *game)
{
	int	old_x;
	int	old_y;

	old_x = game->player.x;
	old_y = game->player.y;
	if (keycode == KEY_ESC)
		quit_game(game);
	else if (keycode == KEY_W)
		game->player.y -= 32;
	else if (keycode == KEY_S)
		game->player.y += 32;
	else if (keycode == KEY_A)
		game->player.x -= 32;
	else if (keycode == KEY_D)
		game->player.x += 32;
	else
		return (0);
	mlx_put_image_to_window(game->mlx, game->window, game->img.player, game->player.x, game->player.y);
	mlx_put_image_to_window(game->mlx, game->window, game->img.floor, old_x, old_y);
	return (0);
}
