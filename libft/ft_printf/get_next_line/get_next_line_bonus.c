/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:13:06 by fracerba          #+#    #+#             */
/*   Updated: 2022/11/14 11:13:11 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin1(char *s1, char *s2)
{
	char	*join;
	int		i;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		*(s1) = '\0';
	}
	if (!s1 || !s2)
		return (0);
	i = ft_strlen(s1) + ft_strlen(s2);
	join = malloc(sizeof(char) * (i + 1));
	if (!join)
		return (0);
	join = ft_strjoin2(s1, s2, join);
	free(s1);
	return (join);
}

char	*ft_read(int fd, char *s1)
{
	char	*temp;
	char	*s2;
	int		i;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (0);
	i = 1;
	s2 = ft_strchr1(s1, '\n');
	while (!s2 && i != 0)
	{
		i = read(fd, temp, BUFFER_SIZE);
		if (i == -1)
		{
			free(temp);
			return (0);
		}
		*(temp + i) = '\0';
		s1 = ft_strjoin1(s1, temp);
		s2 = ft_strchr1(s1, '\n');
	}
	free(temp);
	return (s1);
}

char	*get_next_line(int fd)
{
	static char	*s1[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	*(s1 + fd) = ft_read(fd, *(s1 + fd));
	if (!*(s1 + fd))
		return (0);
	line = ft_get_line(*(s1 + fd));
	*(s1 + fd) = ft_string(*(s1 + fd));
	return (line);
}
