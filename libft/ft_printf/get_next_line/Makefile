# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fracerba <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 12:50:58 by fracerba          #+#    #+#              #
#    Updated: 2023/01/09 12:28:51 by fracerba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

SRCS = get_next_line.c	\
	get_next_line_utils.c	\

BONUS = get_next_line_bonus.c \
	get_next_line_utils_bonus.c	\

OBJS = ${SRCS:.c=.o}

OBJS_BON = ${BONUS:.c=.o}

CC = gcc

RM = rm -f

FLAGS = -Wall -Werror -Wextra

.c.o: 
	${CC} ${FLAGS} -g -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	ar rcs ${NAME} ${OBJS}

bonus: ${OBJS_BON}
	ar rcs ${NAME} ${OBJS_BON}	

all: ${NAME} ${OBJS} ${OBJS_BON}

clean: 
	${RM} ${OBJS} ${OBJS_BON}

fclean: clean 
	${RM} ${NAME}

re: fclean all
