/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:01:07 by fracerba          #+#    #+#             */
/*   Updated: 2022/10/04 12:01:13 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		i;
	int		j;

	i = 0;
	while (*(s1 + i) != '\0')
		i++;
	j = 0;
	while (*(s2 + j) != '\0')
		j++;
	join = malloc((i + j + 1) * 1);
	if (!join)
		return (0);
	i = -1;
	while (*(s1 + (++i)) != '\0')
		*(join + i) = *(s1 + i);
	j = 0;
	while (*(s2 + j) != '\0')
	{
		*(join + i + j) = *(s2 + j);
		j++;
	}
	*(join + i + j) = '\0';
	return (join);
}
