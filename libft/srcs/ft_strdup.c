/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 07:54:06 by lespenel          #+#    #+#             */
/*   Updated: 2023/11/13 19:40:16 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	size_t		len;
	char		*copy;

	len = ft_strlen(s);
	copy = malloc(sizeof (char) * (len + 1));
	if (copy == 0)
		return (0);
	ft_memcpy(copy, s, len + 1);
	return (copy);
}
