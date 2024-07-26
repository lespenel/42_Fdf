/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 00:02:54 by lespenel          #+#    #+#             */
/*   Updated: 2023/11/09 14:26:05 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (big[i] && i != len)
	{
		j = 0;
		while (big[i + j] == little[j] && big[i + j] && little[j]
			&& (i + j) != len)
		{
			j++;
		}
		if (j == ft_strlen(little))
			return ((char *)big + i);
		else
			i++;
	}
	return (0);
}
