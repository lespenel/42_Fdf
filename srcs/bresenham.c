/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 08:23:44 by lespenel          #+#    #+#             */
/*   Updated: 2024/01/26 05:14:46 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "window.h"
#include "mlx.h"
#include <math.h>

void	ft_bresenham(t_data *img, t_vertex *ver1, t_vertex *ver2);
void	ft_bresenham_dx(t_data *img, t_vertex *vert1, t_vertex *ver2, int *d);
void	ft_bresenham_dy(t_data *img, t_vertex *vert1, t_vertex *ver2, int *d);

void	draw_line(t_data *img, t_vertex *ver1, t_vertex *ver2)
{
	unsigned long	a;
	unsigned long	b;

	a = ver1->color;
	b = ver2->color;
	ft_bresenham(img, ver1, ver2);
	ver1->color = b;
	ver2->color = a;
	ft_bresenham(img, ver2, ver1);
	ver1->color = a;
	ver2->color = b;
}

void	ft_bresenham(t_data *img, t_vertex *ver1, t_vertex *ver2)
{
	int	dx;
	int	dy;
	int	delta_xy[2];

	if (ver1 == NULL || ver2 == NULL)
		return ;
	dy = ft_abs((int)ver2->p_y, (int)ver1->p_y);
	dx = ft_abs((int)ver2->p_x, (int)ver1->p_x);
	delta_xy[0] = dx;
	delta_xy[1] = dy;
	if (dy >= dx && (ver1->p_y < HEIGHT || ver2->p_y < HEIGHT))
		ft_bresenham_dy(img, ver1, ver2, delta_xy);
	else if (ver1->p_x < WIDTH || ver2->p_x < WIDTH)
		ft_bresenham_dx(img, ver1, ver2, delta_xy);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= WIDTH || x <= 0)
		return ;
	if (y >= HEIGHT || y <= 0)
		return ;
	dst = data->addr + (y * data->line_length + x * \
		(data->bits_per_pixel >> 3));
	*(unsigned int *)dst = color;
}

void	ft_bresenham_dx(t_data *img, t_vertex *vert1, t_vertex *vert2, int *d)
{
	int	y;
	int	x;
	int	e;

	y = vert1->p_y;
	x = vert1->p_x;
	e = 2 * d[1] - d[0];
	while (x < vert2->p_x)
	{
		my_mlx_pixel_put(img, x, y, vert2->color);
		x++;
		if (e < 0)
			e = e + 2 * d[1];
		else
		{
			if (vert2->p_y - vert1->p_y < 0)
				y = y - 1;
			else
				y = y + 1;
			e = e + 2 * d[1] - 2 * d[0];
		}
	}
}

void	ft_bresenham_dy(t_data *img, t_vertex *vert1, t_vertex *vert2, int *d)
{
	int	y;
	int	x;
	int	e;

	e = 2 * d[0] - d[1];
	y = vert1->p_y;
	x = vert1->p_x;
	while (y < vert2->p_y)
	{
		my_mlx_pixel_put(img, x, y, vert2->color);
		y++;
		if (e < 0)
			e = e + 2 * d[0];
		else
		{
			if (vert2->p_x - vert1->p_x < 0)
				x = x - 1;
			else
				x = x + 1;
			e = e + 2 * d[0] - 2 * d[1];
		}
	}
}
