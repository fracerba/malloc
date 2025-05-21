/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:39:22 by fracerba          #+#    #+#             */
/*   Updated: 2022/10/04 11:39:25 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t			i;
	size_t			j;
	size_t			c;

	i = 0;
	if (*(to_find + i) == '\0')
		return ((char *) str);
	while (*(str + i) != '\0' && i < len)
	{
		if (*(str + i) == *to_find)
		{
			j = 0;
			c = 0;
			while (*(to_find + j) != '\0' && (i + j) < len)
			{
				if (*(str + i + j) != *(to_find + j))
					c = 1;
				j++;
			}
			if (c == 0 && *(to_find + j) == '\0')
				return ((char *)str + i);
		}
		i++;
	}
	return (0);
}
