/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:01:52 by lespenel          #+#    #+#             */
/*   Updated: 2023/11/13 03:02:16 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	cc;

	cc = c;
	i = 0;
	if (n == 0)
		return (0);
	while (((unsigned char *)s)[i] != cc && i < n - 1)
		i++;
	if (((unsigned char *)s)[i] == cc)
		return ((void *)s + i);
	return (0);
}
