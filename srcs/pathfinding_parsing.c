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
