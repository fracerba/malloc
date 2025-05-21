/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:05:43 by fracerba          #+#    #+#             */
/*   Updated: 2022/10/04 12:05:46 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static void	ft_write(int n, int fd)
{
	int		j;
	char	c[10];

	j = 0;
	while (n > 0)
	{
		c[j] = (n % 10) + 48;
		n = n / 10;
		j++;
	}
	j--;
	while (j >= 0)
	{
		write(fd, &c[j], 1);
		j--;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	ft_write(n, fd);
}
