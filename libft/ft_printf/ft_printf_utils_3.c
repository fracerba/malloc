/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:10:37 by fracerba          #+#    #+#             */
/*   Updated: 2022/12/09 10:41:47 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_rev_tab(char *str)
{
	int		i;
	int		s;
	char	c;

	i = 0;
	s = 0;
	while (*(str + s) != '\0')
		s++;
	s = s - 1;
	while (i < (s - i))
	{
		c = *(str + i);
		*(str + i) = *(str + (s - i));
		*(str + (s - i)) = c;
		i++;
	}
	return ;
}

int	ft_check_zero(unsigned int c)
{
	int	i;

	i = 0;
	if (c == 0)
	{
		i = i + ft_putchar(48);
		return (i);
	}
	return (0);
}
