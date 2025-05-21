/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:10:06 by fracerba          #+#    #+#             */
/*   Updated: 2022/12/09 10:40:56 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_pointer(unsigned long long c)
{
	unsigned long long	i;
	unsigned int		j;

	i = c;
	j = 0;
	while (i > 0)
	{
		i = i / 16;
		j++;
	}
	j++;
	return (j);
}

static char	*ft_hex_conv_pointer(unsigned long long c, char *str)
{
	char	*hex;
	int		i;
	int		j;

	i = 0;
	hex = "0123456789abcdef";
	while (c > 0)
	{
		j = c % 16;
		c = c / 16;
		*(str + i) = *(hex + j);
		i++;
	}
	*(str + i) = '\0';
	return (str);
}

static int	ft_puthex_pointer(unsigned long long c)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = ft_count_pointer(c);
	str = malloc(j * 1);
	str = ft_hex_conv_pointer(c, str);
	ft_rev_tab(str);
	i = i + ft_putstr(str);
	free(str);
	return (i);
}

int	ft_putpointer(void *p)
{
	unsigned long long	i;
	int					j;

	if (!p)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	i = (unsigned long long)p;
	write (1, "0x", 2);
	j = ft_puthex_pointer(i) + 2;
	return (j);
}
