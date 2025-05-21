/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:27:14 by fracerba          #+#    #+#             */
/*   Updated: 2022/12/09 10:40:33 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_count(unsigned int c)
{
	unsigned int		i;
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

char	*ft_hex_conv(unsigned int c, char *str)
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

char	*ft_lower_to_upper(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		if (96 < *(str + i) && *(str + i) < 123)
			*(str + i) = *(str + i) - 32;
		i++;
	}
	*(str + i) = '\0';
	return (str);
}

int	ft_puthex_lower(unsigned int c)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = ft_check_zero(c);
	if (j != 0)
		return (j);
	j = ft_hex_count(c);
	str = malloc(j * 1);
	str = ft_hex_conv(c, str);
	ft_rev_tab(str);
	i = i + ft_putstr(str);
	free(str);
	return (i);
}

int	ft_puthex_upper(unsigned int c)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = ft_check_zero(c);
	if (j != 0)
		return (j);
	j = ft_hex_count(c);
	str = malloc(j * 1);
	str = ft_hex_conv(c, str);
	ft_rev_tab(str);
	str = ft_lower_to_upper(str);
	i = i + ft_putstr(str);
	free(str);
	return (i);
}
