/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex_acces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:26:19 by lespenel          #+#    #+#             */
/*   Updated: 2024/01/28 22:04:57 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "vector.h"
#include "window.h"
#include <mlx.h>

void	acess_cmap(t_vector *map, void (*f)(t_topo *, t_vertex *), t_topo *cmap)
{
	size_t		i;
	size_t		j;
	t_vector	*row;
	t_vertex	*vertex;

	i = 0;
	j = 0;
	while (i < map->len)
	{
		row = (t_vector *)at_vector(map, i);
		j = 0;
		while (j < row->len)
		{
			vertex = (t_vertex *)at_vector(row, j);
			(*f)(cmap, vertex);
			j++;
		}
		i++;
	}
}

void	acess_map(t_vector *map, void (*f)(t_vertex *))
{
	size_t		i;
	size_t		j;
	t_vector	*row;
	t_vertex	*vertex;

	i = 0;
	j = 0;
	while (i < map->len)
	{
		row = (t_vector *)at_vector(map, i);
		j = 0;
		while (j < row->len)
		{
			vertex = (t_vertex *)at_vector(row, j);
			(*f)(vertex);
			j++;
		}
		i++;
	}
}

void	draw_vertex_x(t_vector *map, t_data *img)
{
	size_t		i;
	size_t		j;
	t_vector	*row;
	t_vertex	*vertex1;
	t_vertex	*vertex2;

	i = 0;
	while (i < map->len)
	{
		row = (t_vector *)at_vector(map, i);
		j = 0;
		while (j < row->len - 1)
		{
			vertex1 = (t_vertex *)at_vector(row, j);
			vertex2 = (t_vertex *)at_vector(row, j + 1);
			draw_line(img, vertex1, vertex2);
			j++;
		}
		i++;
	}
}

void	draw_vertex_y(t_vector *map, t_data *img)
{
	size_t		i;
	size_t		j;
	t_vector	*row1;
	t_vertex	*vertex1;
	t_vertex	*vertex2;

	i = 0;
	row1 = (t_vector *) at_vector(map, 0);
	while (i < row1->len)
	{
		j = 0;
		while (j < map->len - 1)
		{
			row1 = (t_vector *) at_vector(map, j);
			vertex1 = (t_vertex *)at_vector(row1, i);
			vertex2 = (t_vertex *)at_vector(at_vector(map, j + 1), i);
			draw_line(img, vertex1, vertex2);
			j++;
		}
		i++;
	}
}

void	draw_vertex(t_topo	*c_map)
{
	draw_vertex_x(&c_map->map, &c_map->img);
	draw_vertex_y(&c_map->map, &c_map->img);
}
