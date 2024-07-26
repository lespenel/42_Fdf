/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_charset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 02:14:19 by lespenel          #+#    #+#             */
/*   Updated: 2023/12/29 00:58:33 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t		ft_cut(char const *s, char *set, char **strs);
static size_t		ft_count(char const *s, char *set);
static void			free_strs(char **strs);
int					is_charset(char c, char *set);

char	**ft_split_set(char const *s, char *set)
{
	char	**strs;
	size_t	count;

	count = ft_count(s, set);
	strs = ft_calloc(count + 1, sizeof(char *));
	if (!strs)
		return (NULL);
	if (ft_cut(s, set, strs) == 0)
		return (NULL);
	return (strs);
}

static size_t	ft_cut(char const *s, char *set, char **strs)
{
	size_t	i;
	size_t	count;

	count = 0;
	while (*s)
	{
		i = 0;
		while (is_charset(*s, set) == 0 && s[i])
			i++;
		if (i != 0)
		{
			strs[count] = malloc(sizeof(char) * (i + 1));
			if (!strs[count])
			{
				free_strs(strs);
				return (0);
			}
			ft_strlcpy(strs[count], s, i + 1);
			count++;
			s += i;
		}
		else
			s++;
	}
	return (1);
}

int	is_charset(char c, char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static void	free_strs(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

static size_t	ft_count(char const *s, char *set)
{
	size_t	i;
	size_t	count;

	count = 0;
	while (*s)
	{
		i = 0;
		while (is_charset(*s + i, set) == 0 && s[i])
			i++;
		if (i != 0)
		{
			s += i;
			count++;
		}
		else
			s++;
	}
	return (count);
}
