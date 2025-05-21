# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fracerba <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 12:50:58 by fracerba          #+#    #+#              #
#    Updated: 2022/10/11 12:51:02 by fracerba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c	\
	ft_bzero.c	\
	ft_calloc.c	\
	ft_isalnum.c	\
	ft_isalpha.c	\
	ft_isascii.c	\
	ft_isdigit.c	\
	ft_isprint.c	\
	ft_itoa.c	\
	ft_memchr.c	\
	ft_memcmp.c	\
	ft_memcpy.c	\
	ft_memmove.c	\
	ft_memset.c	\
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c	\
	ft_putstr_fd.c	\
	ft_split.c	\
	ft_strchr.c	\
	ft_strdup.c	\
	ft_striteri.c	\
	ft_strjoin.c	\
	ft_strlcat.c	\
	ft_strlcpy.c	\
	ft_strlen.c	\
	ft_strmapi.c	\
	ft_strncmp.c	\
	ft_strnstr.c	\
	ft_strrchr.c	\
	ft_strtrim.c	\
	ft_substr.c	\
	ft_tolower.c	\
	ft_toupper.c	\

BONUS = ft_lstadd_back.c  \
	ft_lstadd_front.c \
	ft_lstclear.c     \
	ft_lstdelone.c    \
	ft_lstiter.c	  \
	ft_lstlast.c	  \
	ft_lstmap.c	  \
	ft_lstnew.c	  \
	ft_lstsize.c	  \

OBJS = ${SRCS:.c=.o}

OBJS_BON = ${BONUS:.c=.o}

CC = gcc

RM = rm -f

FLAGS = -Wall -Werror -Wextra

PRINTF = ft_printf

PRINTFNAME = libftprintf.a

.c.o: 
	${CC} ${FLAGS} -g -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	make all -C ${PRINTF}
	mv ${PRINTF}/${PRINTFNAME} ${NAME}
	ar rcs ${NAME} ${OBJS}

bonus: ${OBJS_BON}
	make all -C ${PRINTF}
	mv ${PRINTF}/${PRINTFNAME} ${NAME}
	ar rcs ${NAME} ${OBJS_BON}

all: ${NAME} ${OBJS} ${OBJS_BON}

clean: 
	${RM} ${OBJS} ${OBJS_BON}
	make clean -C ${PRINTF}

fclean: clean 
	${RM} ${NAME}
	${RM} ${PRINTFNAME}
	${RM} ${PRINTF}/${PRINTFNAME}

re: fclean all
