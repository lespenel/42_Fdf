/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_mat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 22:48:50 by lespenel          #+#    #+#             */
/*   Updated: 2024/01/24 16:40:52 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "projection.h"
#include <math.h>

void	ft_aply_isometric(t_vertex *vert)
{
	double	x;
	double	y;

	x = (sqrt(2.0) / 2.0) * (vert->p_x - vert->p_y);
	y = (sqrt(2.0 / 3.0) * vert->p_z) - (1.0 / sqrt(6.0) * \
		(vert->p_x + vert->p_y));
	vert->p_x = x;
	vert->p_y = -y;
}

void	aply_weak(t_topo *c_map, t_vertex *v)
{
	float	depth;
	float	sqrt_pxz;
	float	pow_pxz;

	v->p_x /= c_map->buff_scale;
	v->p_y /= c_map->buff_scale;
	v->p_z /= c_map->buff_scale;
	sqrt_pxz = v->p_x * v->p_x + v->p_z * v->p_z;
	pow_pxz = pow(v->p_y - c_map->map_width * 10, 2);
	depth = sqrt(sqrt_pxz + pow_pxz);
	depth /= ((c_map->map_width) * 1 * c_map->buff_scale);
	v->p_x /= depth;
	v->p_y = v->p_z / depth;
	v->p_x *= c_map->buff_scale;
	v->p_y *= c_map->buff_scale;
}
