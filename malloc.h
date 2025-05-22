#ifndef MALLOC_H
# define MALLOC_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/mman.h>
# include <sys/time.h>
# include <sys/resource.h>
# include "libft/libft.h"

typedef struct s_mem
{
	void			*content;
	struct s_mem	*next;
}	t_mem;

void    free(void *ptr);
void    *malloc(size_t size);
void    *realloc(void *ptr, size_t size);
void    show_alloc_mem(void);

#endif