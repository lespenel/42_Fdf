/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 00:06:30 by lespenel          #+#    #+#             */
/*   Updated: 2024/01/24 18:26:26 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "projection.h"

void	translate_right(t_topo *c_map)
{
	if (c_map->projection == WEAK)
		c_map->trans_x += 20 * ((double)c_map->map_width / c_map->map.len);
	else
	{
		c_map->trans_x += 10 * ((double)c_map->map_width / c_map->map.len);
		c_map->trans_y -= 10 * ((double)c_map->map_width / c_map->map.len);
	}
	c_map->trans_mat = get_translation_mat(c_map);
}

void	translate_left(t_topo *c_map)
{
	if (c_map->projection == WEAK)
		c_map->trans_x -= 20 * ((double)c_map->map_width / c_map->map.len);
	else
	{
		c_map->trans_x -= 10 * ((double)c_map->map_width / c_map->map.len);
		c_map->trans_y += 10 * ((double)c_map->map_width / c_map->map.len);
	}
	c_map->trans_mat = get_translation_mat(c_map);
}

void	translate_down(t_topo *c_map)
{
	if (c_map->projection == WEAK)
		c_map->trans_z += 20 * ((double)c_map->map_width / c_map->map.len);
	else
	{
		c_map->trans_x += 10 * ((double)c_map->map_width / c_map->map.len);
		c_map->trans_y += 10 * ((double)c_map->map_width / c_map->map.len);
	}
	c_map->trans_mat = get_translation_mat(c_map);
}

void	translate_up(t_topo *c_map)
{
	if (c_map->projection == WEAK)
		c_map->trans_z -= 20 * ((double)c_map->map_width / c_map->map.len);
	else
	{
		c_map->trans_x -= 10 * ((double)c_map->map_width / c_map->map.len);
		c_map->trans_y -= 10 * ((double)c_map->map_width / c_map->map.len);
	}
	c_map->trans_mat = get_translation_mat(c_map);
}
