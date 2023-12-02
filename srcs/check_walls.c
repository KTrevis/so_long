/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:18:22 by ketrevis          #+#    #+#             */
/*   Updated: 2023/12/02 19:23:40 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "so_long.h"

int	map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	wall_only_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == '1')
		i++;
	return (line[i] == '\0');
}

int	wall_end_start(char *line)
{
	int	i;

	if (line[0] != '1')
		return (0);
	i = 0;
	while (line[i])
		i++;
	if (line[i - 1] == '1')
		return (1);
	return (0);
}

int	line_is_invalid(char **map, int i)
{
	if (i == 0 || i == map_height(map))
	{
		if (wall_only_line(map[i]))
			return (0);
	}
	else if (wall_end_start(map[i]))
		return (0);
	return (1);
}

void	check_surrounding_walls(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (line_is_invalid(map, i))
		{
			ft_printf("Error\nMap is not surrounded by walls");
			free_split(map);
			exit(0);
		}
		i++;
	}
}
