/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:35:24 by fracerba          #+#    #+#             */
/*   Updated: 2022/10/04 11:35:27 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest1;
	unsigned char	*src2;

	i = 0;
	if (!dest && !src)
		return (NULL);
	dest1 = (unsigned char *)dest;
	src2 = (unsigned char *)src;
	if (src2 < dest1)
	{
		while (n-- > 0)
			*(dest1 + n) = *(src2 + n);
	}
	else
	{
		while (n > 0)
		{
			*(dest1 + i) = *(src2 + i);
			i++;
			n--;
		}
	}
	return (dest1);
}
