/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:38:01 by fracerba          #+#    #+#             */
/*   Updated: 2022/10/04 11:38:12 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;	

	i = 0;
	if (n == 0)
		return (0);
	while (*(s1 + i) != '\0' && *(s2 + i) != '\0' && i < (n - 1))
	{
		if (*(s1 + i) != *(s2 + i))
		{
			return ((unsigned char)*(s1 + i) - (unsigned char)*(s2 + i));
		}
		i++;
	}
	return ((unsigned char)*(s1 + i) - (unsigned char)*(s2 + i));
}
