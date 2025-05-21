/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:35:07 by fracerba          #+#    #+#             */
/*   Updated: 2022/10/04 11:35:10 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest1;
	unsigned char	*src2;

	i = 0;
	if (!dest && !src)
		return (NULL);
	dest1 = (unsigned char *)dest;
	src2 = (unsigned char *)src;
	while (i < n)
	{
		*(dest1 + i) = *(src2 + i);
		i++;
	}
	return (dest1);
}
