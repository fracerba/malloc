# Nome dell'eseguibile
NAME = libft_malloc_$(HOSTTYPE).so

# Compilatore e flag
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# File sorgenti e oggetti
SRCS = malloc.c free.c realloc.c show_alloc_mem.c
OBJS = $(SRCS:.c=.o)

# Regola principale
all: $(NAME)

# Creazione dell'eseguibile
$(NAME): $(OBJS)
    $(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# Regola per compilare i file .o
%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

# Pulizia dei file oggetto
clean:
    rm -f $(OBJS)

# Pulizia completa
fclean: clean
    rm -f $(NAME)

# Ricompilazione completa
re: fclean all

.PHONY: all clean fclean re