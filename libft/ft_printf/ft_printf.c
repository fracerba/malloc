/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:26:44 by fracerba          #+#    #+#             */
/*   Updated: 2022/12/09 10:39:14 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(va_list args, const char format)
{
	int	n;

	n = 0;
	if (format == 'c')
		n = n + ft_putchar(va_arg(args, int));
	else if (format == 's')
		n = n + ft_putstr(va_arg(args, char *));
	else if (format == 'i')
		n = n + ft_putnbr(va_arg(args, int));
	else if (format == 'd')
		n = n + ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		n = n + ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (format == 'p')
		n = n + ft_putpointer(va_arg(args, void *));
	else if (format == 'x')
		n = n + ft_puthex_lower(va_arg(args, unsigned int));
	else if (format == 'X')
		n = n + ft_puthex_upper(va_arg(args, unsigned int));
	else if (format == '%')
		n = n + ft_putpercentage();
	return (n);
}

int	ft_printf(const char *pointer, ...)
{
	int		n;
	int		i;
	va_list	args;

	n = 0;
	i = 0;
	va_start(args, pointer);
	if (!pointer)
	{
		write(1, "(null)", 6);
		return (n);
	}
	while (*(pointer + i) != '\0')
	{
		if (*(pointer + i) == '%')
		{
			i++;
			n = n + ft_formats(args, *(pointer + i));
		}
		else
			n = n + ft_putchar(*(pointer + i));
		i++;
	}
	va_end(args);
	return (n);
}
