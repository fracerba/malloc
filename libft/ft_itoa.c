/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:04:33 by fracerba          #+#    #+#             */
/*   Updated: 2022/10/04 12:04:37 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static char	*set_min_int(char *nmb)
{
	char	*nmb2;
	int		i;

	nmb2 = "-2147483648";
	i = 0;
	while (i < 11)
	{
		*(nmb + i) = *(nmb2 + i);
		i++;
	}
	*(nmb + i) = '\0';
	return (nmb);
}

static char	*check_limits(int n)
{
	char	*nmb;

	if (n == 0)
	{
		nmb = malloc(2 * 1);
		if (!nmb)
			return (0);
		*nmb = 48;
		*(nmb + 1) = '\0';
		return (nmb);
	}
	if (n == -2147483648)
	{
		nmb = malloc(12 * 1);
		if (!nmb)
			return (0);
		nmb = set_min_int(nmb);
		return (nmb);
	}
	return (0);
}

static int	counter(int n)
{
	int		c;

	c = 0;
	if (n < 0)
	{
		n = -n;
		c++;
	}
	while (n > 0)
	{
		c++;
		n = n / 10;
	}
	return (c);
}

static char	*string(int n2, int c, char *temp, char *nmb)
{
	int		a;

	a = c - 1;
	if (n2 < 0)
	{
		*(temp + a) = 45;
		n2 = -n2;
	}
	c = 0;
	while (n2 > 0)
	{
		*(temp + c) = (n2 % 10) + 48;
		n2 = n2 / 10;
		c++;
	}
	c = 0;
	while (a >= 0)
	{
		*(nmb + c) = *(temp + a);
		c++;
		a--;
	}
	*(nmb + c) = '\0';
	return (nmb);
}

char	*ft_itoa(int n)
{
	char	*temp;
	char	*nmb;
	int		c;
	int		n2;

	if (n == 0 || n == -2147483648)
	{
		nmb = (char *)check_limits(n);
		return (nmb);
	}
	n2 = n;
	c = counter(n);
	temp = malloc(c * 1);
	nmb = malloc((c + 1) * 1);
	if (!nmb || !temp)
		return (0);
	nmb = string(n2, c, temp, nmb);
	return (nmb);
}
