/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:04:56 by lespenel          #+#    #+#             */
/*   Updated: 2024/01/26 06:19:22 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>

static	long int	ft_atol(const char *nptr);

int	ft_atoi(const char	*nptr)
{
	return (ft_atol(nptr));
}

static long int	ft_atol(const char *nptr)
{
	long int	nb;
	size_t		index;

	index = 0;
	nb = 0;
	while ((*nptr <= 13 && *nptr >= 9) || *nptr == 32)
		nptr++;
	if (nptr[index] == '-' || nptr[index] == '+')
		index++;
	while (nptr[index] <= '9' && nptr[index] >= '0')
	{
		if (INT_MAX / 10 < nb || INT_MAX - (nptr[index] - '0') < nb * 10)
			return (-1);
		nb = nb * 10 + (nptr[index] - '0');
		index++;
	}
	if (nptr[0] == '-')
		return (nb * -1);
	return (nb);
}
