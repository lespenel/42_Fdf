/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 19:26:02 by lespenel          #+#    #+#             */
/*   Updated: 2023/12/27 01:49:52 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	cc;

	cc = c;
	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != cc && s[i])
		i++;
	if (s[i] == cc)
		return ((char *)s + i);
	else
		return (0);
}
