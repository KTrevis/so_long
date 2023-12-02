/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:51:20 by ketrevis          #+#    #+#             */
/*   Updated: 2023/12/02 16:57:25 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <X11/X.h>
#include <X11/keysym.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"
#include "libft.h"
#include "mlx.h"
#include "fcntl.h"

typedef struct	s_game {
	void	*mlx;
	void	*window;
}	t_game;

typedef struct	s_components {
	int	keys;
	int	spawns;
	int	exits;
}	t_components;

enum keys {
	KEY_ESC = 65307,
};

int	handle_input(int keycode, t_game *game);
int	parse_map(char *path);
void	check_map(char **map);

void	quit_game(t_game *game);

#endif
