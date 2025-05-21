/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:27:24 by fracerba          #+#    #+#             */
/*   Updated: 2022/12/09 10:42:04 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int i)
{
	char	c;

	c = (char)i;
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int		i;

	i = 0;
	if (!str)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (*(str + i) != '\0')
	{
		write(1, &*(str + i), 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	char	*s;
	int		i;

	s = ft_itoa(n);
	i = ft_putstr(s);
	free(s);
	return (i);
}

int	ft_putnbr_unsigned(unsigned int c)
{
	char	*str;
	int		i;

	i = ft_check_zero(c);
	if (i != 0)
		return (i);
	str = ft_utoa(c);
	i = ft_putstr(str);
	free(str);
	return (i);
}

int	ft_putpercentage(void)
{
	write (1, "%", 1);
	return (1);
}
