/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:40:27 by fracerba          #+#    #+#             */
/*   Updated: 2022/10/04 11:40:31 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dup;

	i = 0;
	while (*(s + i) != '\0')
		i++;
	dup = malloc((i + 1) * 1);
	if (!dup)
		return (0);
	i = 0;
	while (*(s + i) != '\0')
	{
		*(dup + i) = *(s + i);
		i++;
	}
	*(dup + i) = *(s + i);
	i = 0;
	while (*(s + i) != '\0')
	{
		if (*(dup + i) != *(s + i))
			return (0);
		i++;
	}
	return (dup);
}
