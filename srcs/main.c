/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 05:22:42 by lespenel          #+#    #+#             */
/*   Updated: 2024/07/27 00:47:44 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "fdf.h"
#include "projection.h"
#include "window.h"

static void	init_p_mat(t_topo *c_map);

int	main(int argc, char **argv)
{
	t_topo	complete_map;

	if (argc != 2)
		return (-1);
	init_p_mat(&complete_map);
	create_map(argv[1], &complete_map);
	acess_cmap(&complete_map.map, scale_model, &complete_map);
	window_loop(&complete_map);
	clear_map(&complete_map.map);
	return (0);
}

static void	init_p_mat(t_topo *c_map)
{
	c_map->buff_scale = 1;
	c_map->projection = ISOMETRIC;
	c_map->x_teta = 0.0;
	c_map->y_teta = 0.0;
	c_map->z_teta = 0.0;
	c_map->trans_x = 0;
	c_map->trans_y = 0;
	c_map->trans_z = 0;
	c_map->scale = 1;
	c_map->z_scale = 1;
	c_map->final_mat = mat_init();
	c_map->trans_mat = get_translation_mat(c_map);
	c_map->rx_mat = get_rotate_x_mat(c_map);
	c_map->ry_mat = get_rotate_y_mat(c_map);
	c_map->rz_mat = get_rotate_z_mat(c_map);
	c_map->scale_mat = get_scale_mat(c_map);
	c_map->map_width = 0;
}
