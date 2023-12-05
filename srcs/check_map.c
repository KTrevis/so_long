/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:09:20 by ketrevis          #+#    #+#             */
/*   Updated: 2023/12/05 17:24:14 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "so_long.h"
#include <stdio.h>

void	check_rectangle(char **map)
{
	int	i;
	int	n;

	i = 0;
	n = ft_strlen(map[i]);
	i++;
	while (map[i])
	{
		if (ft_strlen(map[i]) != n)
		{
			ft_printf("Error\nMap is not rectangular");
			free_split(map);
			exit(0);
		}
		i++;
	}
}

void	check_line(char *line, t_components *components)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'C')
			components->keys += 1;
		else if (line[i] == 'P')
			components->spawns += 1;
		else if (line[i] == 'E')
			components->exits += 1;
		else if (line[i] != '1' && line[i] != '0')
		{
			ft_printf("Error\nAn invalid character is present in the map\n");
			exit(0);
		}
		i++;
	}
}

t_components	store_components(char **map)
{
	int				i;
	int				j;
	t_components	components;

	i = 0;
	j = 0;
	components.keys = 0;
	components.spawns = 0;
	components.exits = 0;
	while (map[i])
	{
		check_line(map[i], &components);
		i++;
	}
	return (components);
}

void	check_components(t_components components, t_game *game)
{
	int	err;

	err = 0;
	if (components.exits > 1)
		err = ft_printf("Error\nOnly one exit should be present\n");
	else if (components.exits == 0)
		err = ft_printf("Error\nAn exit is missing\n");
	if (components.spawns > 1)
		err = ft_printf("Error\nOnly one spawn should be present\n");
	else if (components.spawns == 0)
		err = ft_printf("Error\nA spawn is missing\n");
	if (components.keys == 0)
		err = ft_printf("Error\nAt least one collectible should be present\n");
	if (err)
	{
		free_split(game->map);
		exit(0);
	}
	game->max_keys = components.keys;
}

void	check_map(t_game *game)
{
	if (map_height(game->map) < 5 || ft_strlen(game->map[0]) < 3)
	{
		ft_printf("Error\nMap too small");
		free_split(game->map);
		exit(0);
	}
	check_rectangle(game->map);
	check_components(store_components(game->map), game);
	check_surrounding_walls(game->map);
}
