/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_components.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:44:17 by ketrevis          #+#    #+#             */
/*   Updated: 2023/12/11 13:44:23 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		if (check_line(map[i], &components))
		{
			free_split(map);
			exit(0);
		}
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
