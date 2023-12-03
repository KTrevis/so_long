/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:51:20 by ketrevis          #+#    #+#             */
/*   Updated: 2023/12/03 16:08:21 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <X11/X.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <stdio.h>
# include "ft_printf.h"
# include "libft.h"
# include "mlx.h"
# include "fcntl.h"

typedef struct	s_img {
	void	*wall;
	void	*player;
	void	*floor;
	void	*key;
	void	*exit;
}	t_img;

typedef struct	s_player {
	int	x;
	int	y;
}	t_player;

typedef struct	s_game {
	void	*mlx;
	void	*window;
	char	**map;
	t_img	img;
	t_player	player;
}	t_game;

typedef struct	s_components {
	int	keys;
	int	spawns;
	int	exits;
}	t_components;

enum keys {
	KEY_ESC = 65307,
	KEY_W = 119,
	KEY_S = 115,
	KEY_A = 97,
	KEY_D = 100
};

int	handle_input(int keycode, t_game *game);
int	parse_map(char *path, t_game *game);
int	map_height(char **map);
void	check_map(char **map);
void	check_surrounding_walls(char **map);
void	quit_game(t_game *game);
void	draw_map(t_game *game);

#endif
