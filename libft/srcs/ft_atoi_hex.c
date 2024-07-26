/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 22:17:25 by lespenel          #+#    #+#             */
/*   Updated: 2024/01/14 23:20:05 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdint.h>
#include "libft.h"

static int	ft_is_in_base(char c, const char *base);

unsigned long	ft_atoi_hex(char *nptr)
{
	const char	*base = "0123456789abcdef";
	long int	nb;
	int			index;

	nb = 0;
	if (nptr == NULL)
		return (0);
	while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ' || *nptr == '-' \
		|| *nptr == '+')
		nptr++;
	index = ft_is_in_base(*nptr, base);
	while (index != -1 && *nptr)
	{
		index = ft_is_in_base(*nptr, base);
		if (LONG_MAX / 16 < nb || LONG_MAX - index < nb * 16)
			return (0);
		nb = nb * 16 + index;
		nptr++;
	}
	return (nb);
}

static int	ft_is_in_base(char c, const char *base)
{
	uint8_t	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c || base[i] == ft_tolower(c))
			return (i);
		i++;
	}
	return (-1);
}
