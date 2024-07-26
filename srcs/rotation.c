/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 05:04:55 by lespenel          #+#    #+#             */
/*   Updated: 2024/01/24 18:19:34 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "key_bind.h"
#include "projection.h"
#include <math.h>

void	rotate_iso(t_topo *c_map)
{
	c_map->x_teta = 0;
	c_map->y_teta = 0;
	c_map->z_teta = 0;
	c_map->trans_x = 0;
	c_map->trans_y = 0;
	c_map->trans_z = 0;
	c_map->trans_mat = get_translation_mat(c_map);
	c_map->rx_mat = get_rotate_x_mat(c_map);
	c_map->ry_mat = get_rotate_y_mat(c_map);
	c_map->rz_mat = get_rotate_z_mat(c_map);
}

void	rotate_x(t_topo	*c_map)
{
	c_map->x_teta += 0.05;
	c_map->rx_mat = get_rotate_x_mat(c_map);
}

void	rotate_y(t_topo *c_map)
{
	c_map->y_teta += 0.05;
	c_map->ry_mat = get_rotate_y_mat(c_map);
}

void	rotate_z(t_topo *c_map)
{
	c_map->z_teta += 0.05;
	c_map->rz_mat = get_rotate_z_mat(c_map);
}
