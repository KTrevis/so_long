/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding_parsing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:59:26 by ketrevis          #+#    #+#             */
/*   Updated: 2023/12/08 17:09:24 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**replace_objectives(char *path)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	map = open_file(path);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				map[i][j] = '0';
			j++;
		}
		i++;
	}
	return (map);
}

t_coords	get_map_size(char **map)
{
	t_coords	size;

	size.x = ft_strlen(map[0]);
	size.y = map_height(map);
	return (size);
}

void	set_coords(char **map, t_coords *arr)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
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
}

t_coords	*objectives_coords(t_game *game)
{
	char		**map;
	t_coords	*arr;

	map = game->map;
	arr = malloc((game->max_keys + 1) * sizeof(t_coords));
	if (!arr)
		return (NULL);
	set_coords(map, arr);
	return (arr);
}

t_coords	get_spawn(char **map)
{
	int			i;
	int			j;
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
