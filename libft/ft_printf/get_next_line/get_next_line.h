/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:14:07 by fracerba          #+#    #+#             */
/*   Updated: 2022/11/14 11:14:12 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_strchr1(char *s, int c);
int		ft_strlen(char *str);
char	*ft_strjoin1(char *s1, char *s2);
char	*ft_strjoin2(char *s1, char *s2, char *join);
char	*ft_get_line(char *s1);
char	*ft_string(char *s1);
char	*ft_read(int fd, char *s1);

#endif
