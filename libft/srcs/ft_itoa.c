/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 20:55:46 by lespenel          #+#    #+#             */
/*   Updated: 2023/11/13 02:58:06 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*c_str(long int nb, int digits);

char	*ft_itoa(int n)
{
	long int	nb;
	int			digits;

	if (n == 0)
		return (c_str(0, 1));
	nb = n;
	digits = 0;
	while (n != 0)
	{
		n /= 10;
		digits++;
	}
	return (c_str(nb, digits));
}

static char	*c_str(long int nb, int digits)
{
	size_t	neg;
	char	*str;

	neg = 0;
	if (nb < 0)
	{
		nb = -nb;
		neg = 1;
	}
	str = ft_calloc(sizeof(char), digits + neg + 1);
	if (!str)
		return (NULL);
	if (neg == 0)
		digits--;
	while (digits >= 0)
	{
		str[digits] = nb % 10 + '0';
		nb /= 10;
		digits--;
	}
	if (neg != 0)
		str[0] = '-';
	return (str);
}
