/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:51:20 by ketrevis          #+#    #+#             */
/*   Updated: 2023/12/02 13:25:17 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <X11/X.h>
#include <X11/keysym.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"
#include "mlx.h"

typedef struct	s_game {
	void	*mlx;
	void	*window;
}	t_game;

enum {
	KEY_ESC = 65307,
};

int	handle_input(int keycode, t_game *game);

#endif