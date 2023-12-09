/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:14:55 by ketrevis          #+#    #+#             */
/*   Updated: 2023/12/09 10:17:41 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**store_file(int fd)
{
	char	*buffer;
	char	*tmp;
	char	*file;
	char	**split;
	int		n;

	n = 1;
	buffer = malloc(101);
	if (!buffer)
		return (NULL);
	file = ft_strdup("");
	if (!file)
		return (free(buffer), NULL);
	while (n)
	{
		n = read(fd, buffer, 100);
		buffer[n] = '\0';
		tmp = file;
		file = ft_strjoin(file, buffer);
		free(tmp);
		if (!file)
			return (free(buffer), NULL);
	}
	split = ft_split(file, '\n');
	return (free(file), free(buffer), split);
}

char	**open_file(char *path)
{
	int		fd;
	char	**map;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		perror("Error\nReason");
		return (NULL);
	}
	map = store_file(fd);
	close(fd);
	return (map);
}

int	parse_map(char *path, t_game *game)
{
	game->map = open_file(path);
	if (!game->map)
		return (0);
	check_map(game);
	return (1);
}
