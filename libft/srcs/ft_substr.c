/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 20:33:05 by lespenel          #+#    #+#             */
/*   Updated: 2023/11/09 21:47:34 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	slen;
	size_t	i;

	slen = ft_strlen(s) - start;
	if (slen > len)
		slen = len;
	if (start >= ft_strlen(s))
		slen = 0;
	str = malloc(sizeof(char) * slen + 1);
	if (!str)
		return (0);
	i = 0;
	while (i != slen)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
