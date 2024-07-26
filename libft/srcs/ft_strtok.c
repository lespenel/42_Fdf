/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 01:18:42 by lespenel          #+#    #+#             */
/*   Updated: 2024/01/10 06:38:59 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtok(char *str, char *delim)
{
	static char	*next_token = NULL;
	char		*token;
	char		*str_copy;

	if (str == NULL)
		str = next_token;
	if (str == NULL)
		return (NULL);
	str_copy = str;
	while (*str_copy && ft_strchr(delim, *str_copy) != 0)
		str_copy++;
	if (*str_copy == '\0')
		return (NULL);
	token = str_copy;
	while (*str_copy && ft_strchr(delim, *str_copy) == 0)
		str_copy++;
	if (*str_copy != '\0')
	{
		*str_copy = '\0';
		next_token = str_copy + 1;
	}
	else
		next_token = NULL;
	return (token);
}
