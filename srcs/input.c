#include "so_long.h"

void	quit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}

int	handle_input(int keycode, t_game *game)
{
	(void)game;
	if (keycode == KEY_ESC)
		quit_game(game);
	return (0);
}
