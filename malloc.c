#include "malloc.h"

t_mem_manager g_mem_manager = {NULL, NULL, NULL};

void *malloc(size_t size)
{
	if (size == 0)
		return NULL;

	// Allinea la dimensione richiesta
	size_t alignment = sizeof(void *);
	size = (size + alignment - 1) & ~(alignment - 1);

	t_mem_zone **zone_list = NULL;

	// Determina la zona in base alla dimensione
	if (size <= TINY_MAX)
		zone_list = &g_mem_manager.tiny;
	else if (size <= SMALL_MAX)
		zone_list = &g_mem_manager.small;
	else
	{
		size_t total_size = size + sizeof(t_mem_block);
		t_mem_block *block = mmap(NULL, total_size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
		if (block == MAP_FAILED)
			return NULL;

		block->size = size;
		block->is_free = 0;
		block->next = NULL;

		// Aggiungi il blocco alla lista "LARGE"
		if (!g_mem_manager.large)
		{
			g_mem_manager.large = (t_mem_zone *)block;
			g_mem_manager.large->blocks = block;
		}
		else
		{
			t_mem_zone *zone = g_mem_manager.large;
			while (zone->next)
				zone = zone->next;
			zone->next = (t_mem_zone *)block;
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
			return (void *)((char *)block + sizeof(t_mem_block));
		}
		zone = zone->next;
	}

	// Crea una nuova zona se necessario
	size_t block_size = (zone_list == &g_mem_manager.tiny) ? TINY_BLOCK_SIZE : SMALL_BLOCK_SIZE;
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

	zone->blocks = block;
	split_block(block, size);

	return (void *)((char *)block + sizeof(t_mem_block));
}