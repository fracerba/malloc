# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fracerba <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/06 09:13:59 by fracerba          #+#    #+#              #
#    Updated: 2022/12/06 09:14:14 by fracerba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =	ft_printf.c	\
	ft_printf_utils.c \
	ft_printf_utils_2.c \
	ft_printf_utils_3.c \
	ft_printf_hex.c \
	ft_itoa.c \
	ft_utoa.c \

BONUS = ft_printf.c	\
	ft_printf_utils.c \
	ft_printf_utils_2.c \
	ft_printf_utils_3.c \
	ft_printf_hex.c \
	ft_itoa.c \
	ft_utoa.c \

OBJS = ${SRCS:.c=.o}

OBJS_BON = ${BONUS:.c=.o}

CC = gcc

RM = rm -f

FLAGS = -Wall -Werror -Wextra

GNL = get_next_line

GNLNAME = get_next_line.a

.c.o: 
	${CC} ${FLAGS} -g -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	make all -C ${GNL}
	mv ${GNL}/${GNLNAME} ${NAME}
	ar rcs ${NAME} ${OBJS}

bonus: ${OBJS_BON}
	make all -C ${GNL}
	mv ${GNL}/${GNLNAME} ${NAME}
	ar rcs ${NAME} ${OBJS_BON}	

all: ${NAME} ${OBJS} ${OBJS_BON}

clean: 
	${RM} ${OBJS} ${OBJS_BON}
	make clean -C ${GNL}

fclean: clean 
	${RM} ${NAME}
	${RM} ${GNLNAME}
	${RM} ${GNL}/${GNLNAME}

re: fclean all
