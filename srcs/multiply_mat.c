/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply_mat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel </var/spool/mail/lespenel>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:31:49 by lespenel          #+#    #+#             */
/*   Updated: 2024/01/23 04:56:28 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

double	multiply_elem(int x, int y, t_mat4x4 *m1, t_mat4x4 *m2);

void	multiply_mat_vertex(t_mat4x4 *m, t_vertex *v)
{
	double	x;
	double	y;
	double	z;
	double	w;

	x = v->x * m->m[0][0] + v->y * m->m[0][1] + v->z * m->m[0][2] + \
		v->w * m->m[0][3];
	y = v->x * m->m[1][0] + v->y * m->m[1][1] + v->z * m->m[1][2] + \
		v->w * m->m[1][3];
	z = v->x * m->m[2][0] + v->y * m->m[2][1] + v->z * m->m[2][2] + \
		v->w * m->m[2][3];
	w = v->x * m->m[3][0] + v->y * m->m[3][1] + v->z * m->m[3][2] + \
		v->w * m->m[3][3];
	v->p_x = x;
	v->p_y = y;
	v->p_z = z;
	v->p_w = w;
}

t_mat4x4	multiply_mat(t_mat4x4 *m1, t_mat4x4 *m2)
{
	t_mat4x4	m3;
	int			x;
	int			y;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			m3.m[y][x] = multiply_elem(x, y, m1, m2);
			y++;
		}
		x++;
	}
	return (m3);
}

double	multiply_elem(int x, int y, t_mat4x4 *m1, t_mat4x4 *m2)
{
	double	result;

	result = m1->m[y][0] * m2->m[0][x];
	result += m1->m[y][1] * m2->m[1][x];
	result += m1->m[y][2] * m2->m[2][x];
	result += m1->m[y][3] * m2->m[3][x];
	return (result);
}

t_mat4x4	mat_init(void)
{
	t_mat4x4	m;
	int			i;
	int			j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i == j)
				m.m[i][j] = 1.0;
			else
				m.m[i][j] = 0.0;
			j++;
		}
		i++;
	}
	return (m);
}
