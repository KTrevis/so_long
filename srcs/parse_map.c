/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:14:55 by ketrevis          #+#    #+#             */
/*   Updated: 2023/12/02 14:35:31 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "so_long.h"

char	*store_file(int fd)
{
	char	*buffer;
	char	*tmp;
	char	*file;
	int	n;

	buffer = malloc(101);
	n = 1;
	file = ft_strdup("");
	while (n)
	{
		n = read(fd, buffer, 100);
		buffer[n] = '\0';
		tmp = file;
		file = ft_strjoin(file, buffer);
		free(tmp);
	}
	free(buffer);
	close(fd);
	return (file);
}

int	parse_map(char *path)
{
	int	fd;
	char	*map;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Failed to open %s.", path);
		exit(0);
	}
	map = store_file(fd);
	return (0);
}
