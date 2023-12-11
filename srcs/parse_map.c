/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:14:55 by ketrevis          #+#    #+#             */
/*   Updated: 2023/12/11 16:39:02 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "so_long.h"

char	**check_empty_lines(char *str, char *buffer, int fd)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && (i == 0 || str[i - 1] == '\n'))
		{
			ft_printf("Error.\nEmpty lines in file\n");
			free(buffer);
			free(str);
			close(fd);
			exit(0);
		}
		i++;
	}
	return (ft_split(str, '\n'));
}

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
	split = check_empty_lines(file, buffer, fd);
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
