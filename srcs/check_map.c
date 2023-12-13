/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:09:20 by ketrevis          #+#    #+#             */
/*   Updated: 2023/12/13 13:43:01 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_rectangle(char **map)
{
	int	i;
	size_t	n;

	i = 0;
	n = ft_strlen(map[i]);
	i++;
	while (map[i])
	{
		if (ft_strlen(map[i]) != n)
		{
			ft_printf("Error.\nMap is not rectangular\n");
			free_split(map);
			exit(0);
		}
		i++;
	}
}

int	character_invalid(char c)
{
	char	*valids;
	int		i;

	i = 0;
	valids = "01CPEVH";
	if (!BONUS)
		valids = "01CPE";
	while (valids[i])
	{
		if (valids[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int	check_line(char *line, t_components *components)
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
		else if (character_invalid(line[i]))
		{
			ft_printf("Error.\nAn invalid character is present in the map\n");
			return (1);
		}
		i++;
	}
	return (0);
}

void	check_map(t_game *game)
{
	if (game->map[0] == NULL)
	{
		ft_printf("Error.\nEmpty map\n");
		free_split(game->map);
		exit(0);
	}
	check_rectangle(game->map);
	check_components(store_components(game->map), game);
	check_surrounding_walls(game->map);
}
