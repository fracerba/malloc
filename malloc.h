#ifndef MALLOC_H
# define MALLOC_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/mman.h>
# include <sys/time.h>
# include <sys/resource.h>
# include "libft/libft.h"

#define TINY_MAX (size_t)(getpagesize() * 16)		// 64 KB
#define SMALL_MAX (size_t)(getpagesize() * 256)		// 1 MB
#define TINY_ZONE_SIZE (size_t)(TINY_MAX * 100) 	// 6400 KB
#define SMALL_ZONE_SIZE (size_t)(SMALL_MAX * 100)	// 100 MB
#define LARGE_ZONE_SIZE (size_t)(SMALL_MAX * 400)	// 400 MB
#define TINY_BLOCK_SIZE (sizeof(t_mem_block) + TINY_MAX)
#define SMALL_BLOCK_SIZE (sizeof(t_mem_block) + SMALL_MAX)
#define LARGE_BLOCK_SIZE (sizeof(t_mem_block) + LARGE_ZONE_SIZE)

typedef struct s_mem_block
{
	size_t				size;		// Dimensione del blocco
	int					is_free;	// 1 se il blocco è libero, 0 se è occupato
	struct s_mem_block	*next;		// Puntatore al blocco successivo
	void				*original;	// Puntatore all'indirizzo originale del blocco
} t_mem_block;

typedef struct s_mem_zone
{
	void			*start;		// Indirizzo di inizio della zona
	size_t			size;		// Dimensione totale della zona
	t_mem_block		*blocks;	// Lista dei blocchi nella zona
	struct s_mem_zone	*next;	// Puntatore alla zona successiva
} t_mem_zone;

typedef struct s_mem_manager
{
	t_mem_zone	*tiny;	// Zone per allocazioni "TINY"
	t_mem_zone	*small;	// Zone per allocazioni "SMALL"
	t_mem_zone	*large;	// Zone per allocazioni "LARGE"
} t_mem_manager;

// Variabile globale unica
extern t_mem_manager g_mem_manager;

size_t		get_page_size(void);
t_mem_zone	*create_zone(size_t block_size, size_t num_blocks);
t_mem_block	*find_free_block(t_mem_zone *zone, size_t size);
void		split_block(t_mem_block *block, size_t size);
void		remove_zone_from_list(t_mem_zone **head, t_mem_zone *to_remove);

void		free(void *ptr);
void		*malloc(size_t size);
void		*realloc(void *ptr, size_t size);
void		show_alloc_mem(void);

#endif