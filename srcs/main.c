#include "ft_printf.h"
#include "mlx.h"

typedef struct	s_game {
	void	*mlx;
	void	*window;
}	t_game;

int	main(void)
{
	t_game	game;

	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, 1920 / 2, 1080 / 2, "");
	mlx_loop(game.mlx);
}
