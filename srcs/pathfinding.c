/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:50:31 by ketrevis          #+#    #+#             */
/*   Updated: 2023/12/08 16:51:43 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

static t_coords	*objectives_coords(t_game *game)
{
	char	**map;
	t_coords	*arr;
	int		i;
	int		j;
	int		k;

	map = game->map;
	i = 0;
	k = 0;
	arr = malloc((game->max_keys + 1) * sizeof(t_coords));
	if (!arr)
		return (NULL);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
			{
				arr[k].x = j;
				arr[k].y = i;
				k++;
			}
			j++;
		}
		i++;
	}
	return (arr);
}

static t_coords	get_spawn(char **map)
{
	int	i;
	int	j;
	t_coords	player_spawn;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				player_spawn.x = j;
				player_spawn.y = i;
				return (player_spawn);
			}
			j++;
		}
		i++;
	}
	return (player_spawn);
}

static void	fill_map(char **map, t_coords size, t_coords spawn)
{
	t_coords	tmp;

	map[spawn.y][spawn.x] = 'F';
	if (spawn.y > 0 && map[spawn.y - 1][spawn.x] == '0')
	{
		tmp.x = spawn.x;
		tmp.y = spawn.y - 1;
		fill_map(map, size, tmp);
	}
	if (spawn.x > 0 && map[spawn.y][spawn.x - 1] == '0')
	{
		tmp.x = spawn.x - 1;
		tmp.y = spawn.y;
		fill_map(map, size, tmp);
	}
	if (spawn.y < size.y && map[spawn.y + 1][spawn.x] == '0')
	{
		tmp.x = spawn.x;
		tmp.y = spawn.y + 1;
		fill_map(map, size, tmp);
	}
	if (spawn.x < size.x && map[spawn.y][spawn.x + 1] == '0')
	{
		tmp.x = spawn.x + 1;
		tmp.y = spawn.y;
		fill_map(map, size, tmp);
	}
}

static int	free_things(char **map, t_game *game, t_coords *coords)
{
	if (coords)
		free(coords);
	if (map)
		free_split(map);
	return (1);
}

int	impossible_map(char *path, t_game *game)
{
	char		**map;
	t_coords		*coords;
	t_coords		player_spawn;
	t_coords		map_size;
	int		i;

	i = 0;
	player_spawn = get_spawn(game->map);
	map_size = get_map_size(game->map);
	coords = objectives_coords(game);
	map = replace_objectives(path);
	if (!map || !coords)
		return (free_things(map, game, coords));
	fill_map(map, map_size, player_spawn);
	while (i < game->max_keys + 1)
	{
		if (map[coords[i].y][coords[i].x] == '0')
		{
			free_split(game->map);
			return (free_things(map, game, coords));
		}
		i++;
	}
	free_things(map, game, coords);
	return (0);
}
