#include "malloc.h"

t_mem_manager g_mem_manager = {NULL, NULL, NULL};

void *malloc(size_t size)
{
	if (size == 0)
		return NULL;

	// Determina la zona in base alla dimensione
	t_mem_zone **zone_list = NULL;
	if (size <= TINY_MAX)
		zone_list = &g_mem_manager.tiny;
	else if (size <= SMALL_MAX)
		zone_list = &g_mem_manager.small;
	else
	{
		// Alloca una zona per ogni LARGE
		size_t total_size = sizeof(t_mem_zone) + sizeof(t_mem_block) + size;
		t_mem_zone *zone = mmap(NULL, total_size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
		if (zone == MAP_FAILED)
			return NULL;

		zone->start = (void *)zone + sizeof(t_mem_zone);
		zone->size = size;
		zone->nbr_alloc = 1;
		zone->next = NULL;

		// Alloca il blocco all'interno della zona
		t_mem_block *block = (t_mem_block *)zone->start;
		block->size = size;
		block->is_free = 0;
		block->next = NULL;
		block->original = zone->start; // Puntatore all'indirizzo originale del blocco
		zone->blocks = block;

		// Inserisci la nuova zona nella lista large
		if (!g_mem_manager.large)
			g_mem_manager.large = zone;
		else
		{
			t_mem_zone *last = g_mem_manager.large;
			while (last->next)
				last = last->next;
			last->next = zone;
		}

		return (void *)((char *)block + sizeof(t_mem_block));
	}

	// Cerca una zona con spazio disponibile
	t_mem_zone *zone = *zone_list;
	while (zone)
	{
		t_mem_block *block = find_free_block(zone, size);
		if (block)
		{
			block->is_free = 0;
			split_block(block, size);
			zone->nbr_alloc++;
			return (void *)((char *)block + sizeof(t_mem_block));
		}
		zone = zone->next;
	}

	// Crea una nuova zona se necessario
	size_t block_size = 0;
	if (zone_list == &g_mem_manager.tiny)
		block_size = TINY_BLOCK_SIZE;
	else 
		block_size = SMALL_BLOCK_SIZE;

	zone = create_zone(block_size, 100); // Pre-alloca per 100 blocchi
	if (!zone)
		return NULL;
	zone->next = *zone_list;
	*zone_list = zone;

	// Alloca il primo blocco
	t_mem_block *block = (void *)zone->start;
	block->size = zone->size - sizeof(t_mem_block);
	block->is_free = 0;
	block->next = NULL;
	block->original = zone->start; // Puntatore all'indirizzo originale del blocco
	zone->nbr_alloc = 1;
	zone->blocks = block;
	split_block(block, size);

	return (void *)((char *)block + sizeof(t_mem_block));
}