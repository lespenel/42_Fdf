/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 05:12:09 by lespenel          #+#    #+#             */
/*   Updated: 2024/01/26 06:27:01 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "projection.h"

void	up_z(t_topo *c_map)
{
	c_map->z_scale += 0.15;
	c_map->scale_mat = get_scale_mat(c_map);
}

void	minus_z(t_topo *c_map)
{
	c_map->z_scale -= 0.15;
	c_map->scale_mat = get_scale_mat(c_map);
}

void	ft_up_scale(t_topo *c_map)
{
	c_map->scale += 0.05;
	c_map->buff_scale += 0.5;
	c_map->scale_mat = get_scale_mat(c_map);
}

void	ft_down_scale(t_topo *c_map)
{
	c_map->scale -= 0.05;
	c_map->buff_scale -= 0.5;
	c_map->scale_mat = get_scale_mat(c_map);
}
