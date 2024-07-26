/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_minus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:24:42 by lespenel          #+#    #+#             */
/*   Updated: 2024/01/24 11:25:09 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "projection.h"

void	rotate_x_minus(t_topo *c_map)
{
	c_map->x_teta -= 0.05;
	c_map->rx_mat = get_rotate_x_mat(c_map);
}

void	rotate_y_minus(t_topo *c_map)
{
	c_map->y_teta -= 0.05;
	c_map->ry_mat = get_rotate_y_mat(c_map);
}

void	rotate_z_minus(t_topo *c_map)
{
	c_map->z_teta -= 0.05;
	c_map->rz_mat = get_rotate_z_mat(c_map);
}
