/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel </var/spool/mail/lespenel>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 21:44:20 by lespenel          #+#    #+#             */
/*   Updated: 2023/12/26 22:29:02 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	count_words(char *str, char *set)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	if (str == NULL || set == NULL)
		return (0);
	while (str[i])
	{
		j = 0;
		while (is_charset(str[i + j], set) == 0 && str[i + j])
			j++;
		if (j != 0)
		{
			count++;
			i += j;
		}
		else
			i++;
	}
	return (count);
}
