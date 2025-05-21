/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:14:23 by fracerba          #+#    #+#             */
/*   Updated: 2022/11/14 11:14:52 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr1(char *s, int c)
{
	int		i;

	c = (char)c;
	i = 0;
	if (!s)
		return (0);
	while (*(s + i) != '\0')
	{
		if (*(s + i) == c)
			return (s + i);
		i++;
	}
	if (c == '\0')
		return (s + i);
	return (0);
}

char	*ft_strjoin2(char *s1, char *s2, char *join)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 != 0)
	{
		while (*(s1 + i) != '\0')
		{
			*(join + i) = *(s1 + i);
			i++;
		}
	}
	while (*(s2 + j) != '\0')
	{
		*(join + i + j) = *(s2 + j);
		j++;
	}
	*(join + i + j) = '\0';
	return (join);
}

char	*ft_get_line(char *s1)
{
	int		i;
	char	*s2;

	i = 0;
	if (*(s1 + i) == '\0')
		return (0);
	while (*(s1 + i) != '\0' && *(s1 + i) != '\n')
		i++;
	s2 = (char *)malloc(sizeof(char) * (i + 2));
	if (!s2)
		return (0);
	i = 0;
	while (*(s1 + i) != '\0' && *(s1 + i) != '\n')
	{
		*(s2 + i) = *(s1 + i);
		i++;
	}
	if (*(s1 + i) == '\n')
	{
		*(s2 + i) = *(s1 + i);
		i++;
	}
	*(s2 + i) = '\0';
	return (s2);
}

char	*ft_string(char *s1)
{
	int		i;
	int		j;
	char	*s2;

	i = 0;
	while (*(s1 + i) != '\0' && *(s1 + i) != '\n')
		i++;
	if (*(s1 + i) == '\0')
	{
		free(s1);
		return (0);
	}
	s2 = (char *)malloc(sizeof(char) * (ft_strlen(s1) - i + 1));
	if (!s2)
		return (0);
	i++;
	j = 0;
	while (*(s1 + i + j) != '\0')
	{
		*(s2 + j) = *(s1 + i + j);
		j++;
	}
	*(s2 + j) = '\0';
	free(s1);
	return (s2);
}
