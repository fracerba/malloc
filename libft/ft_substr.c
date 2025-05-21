/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:02:44 by fracerba          #+#    #+#             */
/*   Updated: 2022/10/04 12:02:47 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;

	if (!s)
		return (0);
	i = 0;
	while (*(s + i) != '\0')
		i++;
	if (i <= start)
		len = 0;
	i = start;
	while (len && *(s + i) != '\0')
		i++;
	if (len && i <= len)
		len = i;
	sub = malloc((len + 1) * 1);
	if (!sub)
		return (0);
	i = -1;
	while ((++i) < len && *(s + start + i) != '\0')
		*(sub + i) = *(s + start + i);
	*(sub + i) = '\0';
	return (sub);
}
