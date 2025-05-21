/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:36:03 by fracerba          #+#    #+#             */
/*   Updated: 2022/10/04 11:36:06 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	d;
	size_t	s;

	d = 0;
	s = 0;
	i = 0;
	while (*(dst + d) != '\0')
		d++;
	while (*(src + s) != '\0')
		s++;
	if (size > 0 && size > d)
	{
		while (*(src + i) != '\0' && (i + d + 1) < size)
		{
			*(dst + d + i) = *(src + i);
			i++;
		}
		*(dst + d + i) = '\0';
		return (s + d);
	}
	return (s + size);
}
