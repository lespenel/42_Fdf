/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atovertex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 00:48:29 by lespenel          #+#    #+#             */
/*   Updated: 2024/07/27 00:51:38 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

static void	get_color(char *token, t_vertex *v);

void	atovertex(char *line, int y, t_vector *row, t_vector *c_map)
{
	char		*token;
	int			i;
	t_vertex	vertex;

	i = 0;
	token = ft_strtok(line, " ");
	while (token)
	{
		if (token == NULL)
			break ;
		init_vertex(&vertex);
		vertex.z = (double)ft_atoi(token) / 20;
		vertex.x = i;
		vertex.y = y;
		while (*token && *token != ',')
			token++;
		get_color(token, &vertex);
		if (add_vector(row, &vertex) == 1)
			free_line_map(c_map, line);
		token = ft_strtok(NULL, " ");
		i++;
	}
}

static void	get_color(char *token, t_vertex *v)
{
	if (*token)
		v->color = ft_atoi_hex(token + 3);
	else
		v->color = LINES_COLOR;
}
