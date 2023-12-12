/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:51:20 by ketrevis          #+#    #+#             */
/*   Updated: 2023/12/12 11:47:35 by ketrevis         ###   ########.fr       */
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
	void	*enemy;
	void	**numbers;
}	t_img;

typedef struct	s_player {
	unsigned int	x;
	unsigned int	y;
	unsigned int	keys;
	unsigned int	moves;
}	t_player;

typedef struct	s_enemy {
	unsigned int	x;
	unsigned int	y;
	char		orientation;
	int			direction;
}	t_enemy;

typedef struct	s_coords {
	unsigned int	x;
	unsigned int	y;
}	t_coords;

typedef struct	s_game {
	void	*mlx;
	void	*window;
	int		max_keys;
	char	**map;
	t_img	img;
	t_player	player;
	t_enemy	*enemies;
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
int	impossible_map(char *path, t_game *game);
int	check_line(char *line, t_components *components);

char	**open_file(char *path);
char	**replace_objectives(char *path);
char	**replace_objectives(char *path);

t_coords	get_map_size(char **map);
t_coords	get_spawn(char **map);
t_coords	*objectives_coords(t_game *game);

t_components	store_components(char **map);

void	draw_map(t_game *game);
void	check_map(t_game *game);
void	quit_game(t_game *game);
void	check_surrounding_walls(char **map);
void	key_collision(t_game *game, int *old_coordinates);
void	wall_collision(t_game *game, int *old_coordinates);
void	draw_target(t_game *game, int x, int y, char *target);
void	check_components(t_components components, t_game *game);
void	enemy_collision(t_game *game);
void	load_enemies(t_game *game);

#endif
