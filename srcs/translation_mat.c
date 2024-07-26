/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation_mat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel </var/spool/mail/lespenel>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:08:36 by lespenel          #+#    #+#             */
/*   Updated: 2024/01/22 20:52:55 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "projection.h"

t_mat4x4	get_translation_mat(t_topo *c_map)
{
	t_mat4x4	m;

	m = mat_init();
	m.m [0][3] = c_map->trans_x;
	m.m [1][3] = c_map->trans_y;
	m.m [2][3] = c_map->trans_z;
	m.m [3][3] = 1;
	return (m);
}
