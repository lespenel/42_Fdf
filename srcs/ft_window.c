/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 03:49:27 by lespenel          #+#    #+#             */
/*   Updated: 2024/01/26 05:12:48 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "mlx.h"
#include "projection.h"
#include <stdlib.h>

void	init_screen(t_topo *c_map, t_data *img);

int	if_need_redraw(t_topo *c_map)
{
	get_final_mat(c_map);
	acess_cmap(&c_map->map, get_proj_vertex, c_map);
	acess_map(&c_map->map, center_0);
	ft_memset(c_map->img.addr, 0, WIDTH * HEIGHT * 4);
	draw_vertex(c_map);
	mlx_put_image_to_window(c_map->img.mlx, c_map->img.mlx_window,
		c_map->img.img, 0, 0);
	return (0);
}

void	window_loop(t_topo *c_map)
{
	t_data	*img;

	img = &c_map->img;
	init_screen(c_map, img);
	mlx_hook(img->mlx_window, 2, 1L << 0, key_hook, c_map);
	mlx_hook(img->mlx_window, 17, 0, escape_program, c_map);
	mlx_loop_hook(img->mlx, if_need_redraw, c_map);
	mlx_loop(img->mlx);
}

void	init_screen(t_topo *c_map, t_data *img)
{
	img->mlx = mlx_init();
	if (img->mlx == NULL)
		error_handler(c_map, img, 0);
	img->mlx_window = mlx_new_window(img->mlx, WIDTH, HEIGHT, NAME);
	if (img->mlx_window == NULL)
		error_handler(c_map, img, 1);
	img->img = mlx_new_image(img->mlx, WIDTH, HEIGHT);
	if (img->img == NULL)
		error_handler(c_map, img, 2);
	img->need_redraw = 1;
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
						&img->line_length, &img->endian);
	if (img->addr == NULL)
		error_handler(c_map, img, 3);
}
