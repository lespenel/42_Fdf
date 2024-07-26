/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 04:10:41 by lespenel          #+#    #+#             */
/*   Updated: 2024/01/29 19:06:11 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "fdf.h"
#include "key_bind.h"
#include "projection.h"
#include <stdlib.h>

void	draw_new_image(t_topo *c_map, void (*f)(t_topo *v))
{
	f(c_map);
}

int	escape_program(t_topo *c_map)
{
	mlx_destroy_image(c_map->img.mlx, c_map->img.img);
	mlx_destroy_window(c_map->img.mlx, c_map->img.mlx_window);
	mlx_destroy_display(c_map->img.mlx);
	free(c_map->img.mlx);
	clear_map(&c_map->map);
	exit(0);
}

t_key_func	get_key_func(int keycode)
{
	unsigned int	i;
	const t_key		key[] = {{W_KEY, ft_up_scale}, {S_KEY, ft_down_scale}, \
	{RIGHT_ARROW, translate_right}, {LEFT_ARROW, translate_left}, \
	{DOWN_ARROW, translate_down}, {UP_ARROW, translate_up}, {PLUS_KEY, up_z}, \
	{MINUS_KEY, minus_z}, {NUM_4, rotate_y}, {NUM_2, rotate_x}, \
	{NUM_7, rotate_z}, {NUM_8, rotate_x_minus}, {NUM_6, rotate_y_minus}, \
	{NUM_9, rotate_z_minus}, {I_KEY, rotate_iso}};

	i = 0;
	while (i != 15)
	{
		if (key[i].key == (unsigned int)keycode)
			return (key[i].func);
		i++;
	}
	return (NULL);
}

int	key_hook(int keycode, t_topo *c_map)
{
	void	*f;

	f = get_key_func(keycode);
	if (keycode == ESC_KEY)
		escape_program(c_map);
	if (keycode == P_KEY)
	{
		if (c_map->projection == 0)
			c_map->projection = 1;
		else
			c_map->projection = 0;
	}
	if (f != NULL)
	{
		draw_new_image(c_map, f);
	}
	return (0);
}
