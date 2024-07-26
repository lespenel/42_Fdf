/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 23:28:47 by lespenel          #+#    #+#             */
/*   Updated: 2024/01/24 18:36:35 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "fdf.h"

int		escape_program(t_topo *img);
int		key_hook(int keycode, t_topo *c_map);
void	draw_vertex(t_topo	*c_map);
void	window_loop(t_topo *c_map);
void	draw_line(t_data *img, t_vertex *vect1, t_vertex *vect2);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif
