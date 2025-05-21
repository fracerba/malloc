/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:42:14 by fracerba          #+#    #+#             */
/*   Updated: 2022/10/04 11:42:16 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	c = (char)c;
	i = 0;
	while (*(s + i) != '\0')
	{
		i++;
	}
	if (c == '\0')
		return ((char *) s + i);
	while (i >= 0)
	{
		if (*(s + i) == c)
			return ((char *) s + i);
		i--;
	}
	return (0);
}
