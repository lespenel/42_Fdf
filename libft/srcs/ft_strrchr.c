/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 19:58:38 by lespenel          #+#    #+#             */
/*   Updated: 2023/11/13 05:07:40 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		i;
	char		cc;

	i = ft_strlen(s);
	cc = c;
	while (s[i] != cc && i != 0)
		i--;
	if (s[i] == cc)
		return ((char *)s + i);
	return (0);
}
