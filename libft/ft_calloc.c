/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:40:13 by fracerba          #+#    #+#             */
/*   Updated: 2022/10/04 11:40:16 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*call;
	size_t			i;
	unsigned char	*temp;

	i = 0;
	call = malloc(nmemb * size);
	if (!call)
		return (0);
	temp = (unsigned char *)call;
	while (i < (nmemb * size))
	{
		*(temp + i) = 0;
		i++;
	}
	return (call);
}
