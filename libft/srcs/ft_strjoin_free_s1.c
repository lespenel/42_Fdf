/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free_s1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 02:02:22 by lespenel          #+#    #+#             */
/*   Updated: 2023/11/28 02:09:01 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/types.h>
#include <stdlib.h>

char	*ft_strjoin_free_s1(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	ssize_t	j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	str = malloc(sizeof(char) * (i + j + 1));
	if (str == NULL)
	{
		free(s1);
		return (NULL);
	}
	ft_memcpy(str, s1, i);
	ft_memcpy(str + i, s2, j + 1);
	free(s1);
	return (str);
}
