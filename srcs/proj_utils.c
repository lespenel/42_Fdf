/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proj_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 22:43:47 by lespenel          #+#    #+#             */
/*   Updated: 2024/01/24 11:18:50 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "projection.h"

void	center_model(t_topo *c_map, t_vertex *v)
{
	v->x -= (-0.5 + (double)c_map->map_width / 2);
	v->y -= (-0.5 + (double)c_map->map.len / 2);
}

void	scale_model(t_topo *c_map, t_vertex *v)
{
	double	scale;

	scale = (double)WIDTH / (double)c_map->map_width;
	v->x *= scale;
	v->y *= scale;
	v->z *= scale;
	v->x -= (-0.5 + (double)c_map->map_width / 2) * scale;
	v->y -= (-0.5 + (double)c_map->map.len / 2) * scale;
	v->x /= 2;
	v->y /= 2;
}

void	center_0(t_vertex *v)
{
	v->p_x += (double)WIDTH / 2;
	v->p_y += (double)HEIGHT / 2;
}
