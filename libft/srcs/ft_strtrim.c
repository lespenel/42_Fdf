/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 22:53:36 by lespenel          #+#    #+#             */
/*   Updated: 2023/11/13 05:08:32 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*str;

	if (!*set)
		return (ft_strdup(s1));
	while (is_charset(*s1, (char *)set))
		s1++;
	if (!*s1)
		return (ft_strdup(""));
	len = ft_strlen(s1) - 1;
	while (is_charset(s1[len], (char *)set))
		len--;
	str = malloc(sizeof(char) * (len + 2));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, len + 1);
	str[len + 1] = '\0';
	return (str);
}
