/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_mat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel </var/spool/mail/lespenel>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:41:44 by lespenel          #+#    #+#             */
/*   Updated: 2024/01/22 12:36:07 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <projection.h>
#include <math.h>

t_mat4x4	get_rotate_x_mat(t_topo *c_map)
{
	t_mat4x4	m;

	m = mat_init();
	m.m[0][0] = 1;
	m.m[1][1] = cos(c_map->x_teta);
	m.m[2][1] = sin(c_map->x_teta);
	m.m[1][2] = -m.m[2][1];
	m.m[2][2] = m.m[1][1];
	m.m[3][3] = 1;
	return (m);
}

t_mat4x4	get_rotate_y_mat(t_topo *c_map)
{
	t_mat4x4	m;

	m = mat_init();
	m.m[0][0] = cos(c_map->y_teta);
	m.m[1][1] = 1;
	m.m[0][2] = sin(c_map->y_teta);
	m.m[2][0] = -m.m[0][2];
	m.m[2][2] = m.m[0][0];
	m.m[3][3] = 1;
	return (m);
}

t_mat4x4	get_rotate_z_mat(t_topo *c_map)
{
	t_mat4x4	m;

	m = mat_init();
	m.m[0][0] = cos(c_map->z_teta);
	m.m[0][1] = -sin(c_map->z_teta);
	m.m[1][0] = -m.m[0][1];
	m.m[1][1] = m.m[0][0];
	m.m[2][2] = 1;
	m.m[3][3] = 1;
	return (m);
}
