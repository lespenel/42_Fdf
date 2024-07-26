/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 00:47:12 by lespenel          #+#    #+#             */
/*   Updated: 2024/01/28 21:58:14 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <stdlib.h>

void	check_file_extension(char *path)
{
	int		len;
	int		i;
	char	*f_ext;

	if (path == NULL)
		exit(-1);
	len = 0;
	f_ext = ".fdf";
	while (path[len])
		len++;
	if (len < 4)
		exit(-1);
	len--;
	i = 0;
	while (path[len - i] == f_ext[3 - i] && i < 4)
		i++;
	if (i != 4)
		exit(-1);
}

void	free_line_map(t_vector *c_map, char *line)
{
	clear_map(c_map);
	free(line);
	exit(1);
}

void	error_handler(t_topo *c_map, t_data *img, int param)
{
	if (param == 3)
		mlx_destroy_image(img->mlx, img->img);
	if (param == 2 || param == 3)
		mlx_destroy_window(img->mlx, img->mlx_window);
	if (param == 1 || param == 2 || param == 3)
	{
		mlx_destroy_display(img->mlx);
		free(img->mlx);
	}
	clear_map(&c_map->map);
	exit(1);
}

void	clear_map(t_vector *map)
{
	size_t	i;

	i = 0;
	while (i < map->len)
	{
		clear_vector(at_vector(map, i));
		i++;
	}
	clear_vector(map);
}

int	ft_abs(int a, int b)
{
	long int	abs;

	abs = (a - b);
	if (abs >= 0)
		return (abs);
	else
		return (abs * (-1));
}
