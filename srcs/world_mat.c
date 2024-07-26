/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_mat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel </var/spool/mail/lespenel>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:44:36 by lespenel          #+#    #+#             */
/*   Updated: 2024/01/26 01:53:34 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#include "projection.h"

void	get_final_mat(t_topo *c_map)
{
	c_map->final_mat = mat_init();
	c_map->final_mat = multiply_mat(&c_map->scale_mat, &c_map->final_mat);
	c_map->final_mat = multiply_mat(&c_map->ry_mat, &c_map->final_mat);
	c_map->final_mat = multiply_mat(&c_map->rx_mat, &c_map->final_mat);
	c_map->final_mat = multiply_mat(&c_map->rz_mat, &c_map->final_mat);
	c_map->final_mat = multiply_mat(&c_map->trans_mat, &c_map->final_mat);
}

void	get_proj_vertex(t_topo *c_map, t_vertex *v)
{
	multiply_mat_vertex(&c_map->final_mat, v);
	if (c_map->projection == ISOMETRIC)
		ft_aply_isometric(v);
	else if (c_map->projection == WEAK)
		aply_weak(c_map, v);
}
