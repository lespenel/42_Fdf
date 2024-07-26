/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 23:40:06 by lespenel          #+#    #+#             */
/*   Updated: 2024/01/28 22:00:30 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTION_H
# define PROJECTION_H

# define WEAK 0
# define ISOMETRIC 1

# include "fdf.h"
# include "window.h"

void		get_final_mat(t_topo *c_map);
t_mat4x4	get_translation_mat(t_topo *c_map);
t_mat4x4	get_scale_mat(t_topo *c_map);
t_mat4x4	get_rotate_x_mat(t_topo *c_map);
t_mat4x4	get_rotate_y_mat(t_topo *c_map);
t_mat4x4	get_rotate_z_mat(t_topo *c_map);
void		get_proj_vertex(t_topo *c_map, t_vertex *v);
void		acess_cmap(t_vector *map, void (*f)(t_topo *, t_vertex *), \
		t_topo *c);

void		aply_weak(t_topo *c_map, t_vertex *v);
t_mat4x4	mat_init(void);
double		multiply_elem(int x, int y, t_mat4x4 *m1, t_mat4x4 *m2);
t_mat4x4	multiply_mat(t_mat4x4 *m1, t_mat4x4 *m2);
void		multiply_mat_vertex(t_mat4x4 *m, t_vertex *v);

void		scale_model(t_topo *c_map, t_vertex *v);
void		center_model(t_topo *c_map, t_vertex *v);
void		center_0(t_vertex *v);

void		up_z(t_topo *c_map);
void		minus_z(t_topo *c_map);
void		ft_up_scale(t_topo *c_map);
void		ft_down_scale(t_topo *c_map);

void		rotate_x(t_topo *c_map);
void		rotate_y(t_topo *c_map);
void		rotate_z(t_topo *c_map);
void		rotate_x_minus(t_topo *c_map);
void		rotate_y_minus(t_topo *c_map);
void		rotate_z_minus(t_topo *c_map);

void		translate_left(t_topo *c_map);
void		translate_right(t_topo *c_map);
void		translate_up(t_topo *c_map);
void		translate_down(t_topo *c_mmp);

#endif
