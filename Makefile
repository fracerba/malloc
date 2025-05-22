# Variabile HOSTTYPE
ifeq ($(HOSTTYPE),)
    HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

# Nome dell'eseguibile
NAME = libft_malloc_$(HOSTTYPE).so
LINK_NAME = libft_malloc.so

# Compilatore e flag
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# File sorgenti e oggetti
SRCS = malloc.c free.c realloc.c show_alloc_mem.c
OBJS = $(SRCS:.c=.o)

# Regola principale
all: libft $(NAME) symlink

# Creazione dell'eseguibile
$(NAME): $(OBJS)
    $(CC) $(CFLAGS) -shared -o $(NAME) $(OBJS)

# Creazione del collegamento simbolico
symlink:
    ln -sf $(NAME) $(LINK_NAME)

# Compilazione della libreria libft
libft:
    $(MAKE) -C libft

# Regola per compilare i file .o
%.o: %.c
    $(CC) $(CFLAGS) -fPIC -c $< -o $@

# Pulizia dei file oggetto
clean:
    rm -f $(OBJS)
    $(MAKE) -C libft clean

# Pulizia completa
fclean: clean
    rm -f $(NAME) $(LINK_NAME)
    $(MAKE) -C libft fclean

# Ricompilazione completa
re: fclean all

.PHONY: all clean fclean re libft symlink