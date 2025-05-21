/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:59:37 by fracerba          #+#    #+#             */
/*   Updated: 2022/10/04 11:59:40 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	counter(char const *s, char c)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) != c)
		{
			k++;
			while (*(s + i) != c && *(s + i) != '\0')
				i++;
		}
		else
			i++;
	}
	return (k + 1);
}

static char	**alloc_split(char const *s, char c, char **split)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) != c)
		{
			while (*(s + i + j) != c && *(s + i + j) != '\0')
				j++;
			split[k] = malloc((j + 1) * 1);
			if (!split[k])
				return (0);
			k++;
			i = i + j;
			j = 0;
		}
		else
			i++;
	}
	return (split);
}

static char	**split_string(char const *s, char c, char **split, int j)
{
	int		i;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) != c)
		{
			while (*(s + i + j) != c && *(s + i + j) != '\0')
			{
				split[k][j] = *(s + i + j);
				j++;
			}
			split[k][j] = 0;
			k++;
			i = i + j;
			j = 0;
		}
		else
			i++;
	}
	split[k] = 0;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	int		j;
	int		k;
	char	**split;

	if (!s)
		return (0);
	j = counter(s, c);
	k = sizeof(char *);
	split = malloc(j * k);
	if (!split)
		return (0);
	j = 0;
	split = alloc_split(s, c, split);
	if (!split)
		return (0);
	split = split_string(s, c, split, j);
	return (split);
}
