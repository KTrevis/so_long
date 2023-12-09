/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:01:07 by ketrevis          #+#    #+#             */
/*   Updated: 2023/12/09 13:53:29 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "mlx.h"
#include "so_long.h"

void	quit_game(t_game *game)
{
	int	i;

	i = 0;
	mlx_destroy_image(game->mlx, game->img.wall);
	mlx_destroy_image(game->mlx, game->img.player);
	mlx_destroy_image(game->mlx, game->img.floor);
	mlx_destroy_image(game->mlx, game->img.exit);
	mlx_destroy_image(game->mlx, game->img.key);
	while (i <= 9)
	{
		mlx_destroy_image(game->mlx, game->img.numbers[i]);
		i++;
	}
	free(game->img.numbers);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free_split(game->map);
	free(game->mlx);
	exit(0);
}

int	collision_check(t_game *game, int *old_coordinates)
{
	char	collider;

	collider = game->map[game->player.y / 32][game->player.x / 32];
	if (collider != '1')
	{
		game->player.moves++;
		ft_printf("%d\n", game->player.moves);
	}
	else
	{
		game->player.x = old_coordinates[0];
		game->player.y = old_coordinates[1];
	}
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
	return (collider);
}

int	handle_key(int keycode, t_game *game)
{
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
	return (1);
}

void	display_moves(t_game *game)
{
	char	*str;
	int		i;
	int		x;

	x = 0;
	i = 0;
	str = ft_itoa(game->player.moves);
	if (!str)
		return ;
	while (str[i])
	{
		mlx_put_image_to_window(
			game->mlx, game->window, game->img.numbers[str[i] - '0'], x, 0);
		x += 32;
		i++;
	}
	free(str);
}

int	handle_input(int keycode, t_game *game)
{
	int	old_coordinates[2];

	old_coordinates[0] = game->player.x;
	old_coordinates[1] = game->player.y;
	if (!handle_key(keycode, game))
		return (0);
	collision_check(game, old_coordinates);
	if (game->map[old_coordinates[1] / 32][old_coordinates[0] / 32] == 'E')
		draw_target(game, old_coordinates[0], old_coordinates[1], "exit");
	else
		draw_target(game, old_coordinates[0], old_coordinates[1], "floor");
	draw_target(game, game->player.x, game->player.y, "player");
	display_moves(game);
	return (0);
}
