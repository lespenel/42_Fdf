/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:48:30 by lespenel          #+#    #+#             */
/*   Updated: 2023/11/13 05:25:12 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	sizee;

	sizee = nmemb * size;
	if (size != 0)
		if (sizee / size != nmemb)
			return (NULL);
	ptr = malloc(sizeof(char) * sizee);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, sizee);
	return (ptr);
}
