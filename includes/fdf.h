/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 23:04:15 by lespenel          #+#    #+#             */
/*   Updated: 2024/07/27 00:51:34 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stddef.h>
# include "vector.h"

# define NAME "Fdf lespenel"
# define WIDTH 1920
# define HEIGHT 1080
# define LINES_COLOR 802020

typedef struct s_data
{
	void	*img;
	void	*mlx;
	void	*mlx_window;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		need_redraw;
}	t_data;

typedef struct s_mat4x4
{
	double	m[4][4];
}	t_mat4x4;

typedef struct s_topo
{
	t_vector	map;
	size_t		map_width;
	t_data		img;
	int			projection;
	double		scale;
	double		z_scale;
	double		x_teta;
	double		y_teta;
	double		z_teta;
	double		trans_x;
	double		trans_y;
	double		trans_z;
	t_mat4x4	rx_mat;
	t_mat4x4	ry_mat;
	t_mat4x4	rz_mat;
	t_mat4x4	trans_mat;
	t_mat4x4	scale_mat;
	t_mat4x4	final_mat;
	double		buff_scale;
}	t_topo;

typedef struct s_vertex
{
	double			x;
	double			y;
	double			z;
	double			w;
	double			p_x;
	double			p_y;
	double			p_z;
	double			p_w;
	unsigned long	color;
}	t_vertex;

int		ft_abs(int a, int b);
void	free_line_map(t_vector *c_map, char *line);
void	ft_aply_isometric(t_vertex *vert);
void	print_vertex(t_vertex *v);
void	acess_map(t_vector *map, void (*f)(t_vertex *));
void	clear_map(t_vector *map);
void	create_map(char *path, t_topo *new_map);
void	vertex_init(t_vertex *vertex);
void	init_vertex(t_vertex *v);
void	check_file_extension(char *path);
void	rotate_iso(t_topo *c_map);
void	init_vertex(t_vertex *v);
void	error_handler(t_topo *c_map, t_data *img, int param);
void	atovertex(char *nptr, int y, t_vector *row, t_vector *map);

#endif
