/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:35:58 by fracerba          #+#    #+#             */
/*   Updated: 2022/12/09 12:43:26 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count(unsigned int c)
{
	unsigned int		i;
	unsigned int		j;

	i = c;
	j = 0;
	while (i > 0)
	{
		i = i / 10;
		j++;
	}
	j++;
	return (j);
}

char	*ft_utoa(unsigned int c)
{
	int		i;
	char	a;
	char	*str;

	i = ft_count(c);
	str = malloc(i * 1);
	i = 0;
	while (c > 0)
	{
		a = (c % 10) + 48;
		c = c / 10;
		*(str + i) = a;
		i++;
	}
	*(str + i) = '\0';
	ft_rev_tab(str);
	return (str);
}
