/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:26:57 by fracerba          #+#    #+#             */
/*   Updated: 2022/12/09 10:40:08 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdint.h>
# include <limits.h>

int		ft_printf(const char *pointer, ...);
int		ft_putchar(int i);
int		ft_putnbr(int n);
int		ft_putstr(char *str);
int		ft_putnbr_unsigned(unsigned int n);
int		ft_putpercentage(void);
int		ft_putpointer(void *p);
int		ft_puthex_upper(unsigned int c);
int		ft_puthex_lower(unsigned int c);
int		ft_formats(va_list args, const char format);
int		ft_hex_count(unsigned int c);
int		ft_check_zero(unsigned int c);
void	ft_rev_tab(char *str);
char	*ft_hex_conv(unsigned int c, char *str);
char	*ft_lower_to_upper(char *str);
int		ft_count(unsigned int c);
char	*ft_itoa(int n);
char	*ft_utoa(unsigned int c);

#endif
