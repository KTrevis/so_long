/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:50:31 by ketrevis          #+#    #+#             */
/*   Updated: 2023/12/08 17:23:42 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

static void	norm_hack(t_coords *tmp, t_coords spawn, int flag)
{
	if (flag == 0)
	{
		tmp->x = spawn.x;
		tmp->y = spawn.y - 1;
		return ;
	}
	if (flag == 1)
	{
		tmp->x = spawn.x - 1;
		tmp->y = spawn.y;
		return ;
	}
	if (flag == 2)
	{
		tmp->x = spawn.x;
		tmp->y = spawn.y + 1;
		return ;
	}
	if (flag == 3)
	{
		tmp->x = spawn.x + 1;
		tmp->y = spawn.y;
		return ;
	}
}

static void	fill_map(char **map, t_coords size, t_coords spawn)
{
	t_coords	tmp;

	map[spawn.y][spawn.x] = 'F';
	if (spawn.y > 0 && map[spawn.y - 1][spawn.x] == '0')
	{
		norm_hack(&tmp, spawn, 0);
		fill_map(map, size, tmp);
	}
	if (spawn.x > 0 && map[spawn.y][spawn.x - 1] == '0')
	{
		norm_hack(&tmp, spawn, 1);
		fill_map(map, size, tmp);
	}
	if (spawn.y < size.y && map[spawn.y + 1][spawn.x] == '0')
	{
		norm_hack(&tmp, spawn, 2);
		fill_map(map, size, tmp);
	}
	if (spawn.x < size.x && map[spawn.y][spawn.x + 1] == '0')
	{
		norm_hack(&tmp, spawn, 3);
		fill_map(map, size, tmp);
	}
}

static int	free_pathfinding(char **map, t_game *game, t_coords *coords, int f)
{
	if (f)
		free_split(game->map);
	if (coords)
		free(coords);
	if (map)
		free_split(map);
	return (1);
}

int	impossible_map(char *path, t_game *game)
{
	char			**map;
	t_coords		*coords;
	t_coords		player_spawn;
	t_coords		map_size;
	int				i;

	i = 0;
	player_spawn = get_spawn(game->map);
	map_size = get_map_size(game->map);
	coords = objectives_coords(game);
	if (!coords)
		return (free_pathfinding(map, game, coords, 1));
	map = replace_objectives(path);
	if (!map)
		return (free_pathfinding(map, game, coords, 1));
	fill_map(map, map_size, player_spawn);
	while (i < game->max_keys + 1)
	{
		if (map[coords[i].y][coords[i].x] == '0')
			return (free_pathfinding(map, game, coords, 1));
		i++;
	}
	free_pathfinding(map, game, coords, 0);
	return (0);
}
