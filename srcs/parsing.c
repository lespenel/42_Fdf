/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:26:05 by lespenel          #+#    #+#             */
/*   Updated: 2024/07/27 00:49:59 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"
#include "libft.h"
#include "vector.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static int		read_file(int fd, t_topo *c_map, t_vector *map);

void	create_map(char *path, t_topo *complete_map)
{
	t_vector	map;
	int			fd;

	check_file_extension(path);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit(1);
	init_vector(&map, sizeof(t_vector));
	if (read_file(fd, complete_map, &map) == -1)
	{
		clear_map(&map);
		exit(1);
	}
	complete_map->map = map;
	close(fd);
}

static int	read_file(int fd, t_topo *c_map, t_vector *map)
{
	char		*line;
	int			y;
	t_vector	row;

	y = 0;
	line = get_next_line(fd);
	if (line == NULL)
		return (-1);
	while (line)
	{
		if (line != NULL)
		{
			init_vector(&row, sizeof(t_vertex));
			atovertex(line, y, &row, map);
			if (add_vector(map, &row) == 1)
				return (clear_vector(&row), free(line), -1);
			free(line);
			y++;
		}
		if (row.len > c_map->map_width)
			c_map->map_width = row.len;
		line = get_next_line(fd);
	}
	free(line);
	return (0);
}
