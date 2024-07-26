/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_mat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 06:13:29 by lespenel          #+#    #+#             */
/*   Updated: 2024/01/26 06:13:31 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "projection.h"
#include <math.h>

t_mat4x4	get_scale_mat(t_topo *c_map)
{
	t_mat4x4	m;

	m = mat_init();
	m.m[0][0] = c_map->scale;
	m.m[1][1] = c_map->scale;
	m.m[2][2] = c_map->z_scale + c_map->scale;
	m.m[3][3] = 1;
	return (m);
}
