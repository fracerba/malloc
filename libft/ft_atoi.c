/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:39:39 by fracerba          #+#    #+#             */
/*   Updated: 2022/10/04 11:39:42 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	nb;
	int	s;
	int	i;

	nb = 0;
	i = 0;
	s = 1;
	while ((*(nptr + i) > 8 && *(nptr + i) < 14) || *(nptr + i) == 32)
	{
		i++;
	}
	if (*(nptr + i) == 43 || *(nptr + i) == 45)
	{
		if (*(nptr + i) == 45)
			s = -s;
		i++;
	}
	while (*(nptr + i) > 47 && *(nptr + i) < 58)
	{
		nb = nb * 10;
		nb = nb + (*(nptr + i) - 48);
		i++;
	}
	return (nb * s);
}
