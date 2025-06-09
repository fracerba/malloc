#include "malloc.h"

int all_blocks_free(t_mem_zone *zone)
{
    t_mem_block *block = zone->blocks;
    while (block)
    {
        if (!block->is_free)
            return 0;
        block = block->next;
    }
    return 1;
}

t_mem_zone *find_zone(t_mem_block *block)
{
	t_mem_zone *zone = NULL;
	t_mem_zone *zone_lists[] = {g_mem_manager.tiny, g_mem_manager.small, g_mem_manager.large};
    for (int i = 0; i < 3; i++)
    {
        t_mem_zone *z = zone_lists[i];
        while (z)
        {
            // Il blocco appartiene a questa zona se il suo indirizzo è compreso tra start e start+size
            if ((void *)block >= z->start && (void *)block < (z->start + z->size))
            {
                zone = z;
                break;
            }
            z = z->next;
        }
        if (zone)
            break;
    }
    if (!zone)
        return NULL;
}

void free(void *ptr)
{
	if (!ptr)
		return;

	t_mem_block *block = (t_mem_block *)((char *)ptr - sizeof(t_mem_block));
	block->is_free = 1;

	t_mem_zone *zone = find_zone(block);
	if (!zone)
		return;

	if (zone->nbr_alloc > 0)
		zone->nbr_alloc--;

	// Coalescing con blocco successivo
	while (block->next && block->next->is_free)
	{
		block->size += sizeof(t_mem_block) + block->next->size;
		block->next = block->next->next;
	}

	// Coalescing con blocco precedente
	t_mem_block *prev = NULL;
	t_mem_block *curr = zone->blocks;
	while (curr && curr != block)
	{
		prev = curr;
		curr = curr->next;
	}
	if (curr == block && prev && prev->is_free)
	{
		prev->size += sizeof(t_mem_block) + block->size;
		prev->next = block->next;
	}

	// Se il blocco appartiene a "LARGE", rilascia la memoria
	if (block->size > SMALL_MAX)
	{
		remove_zone_from_list(&g_mem_manager.large, zone);
		munmap(block->original, block->size + sizeof(t_mem_block) + sizeof(t_mem_zone));
		return;
	}

	if (all_blocks_free(zone))
	{
		if (zone == g_mem_manager.tiny)
			remove_zone_from_list(&g_mem_manager.tiny, zone);
		else if (zone == g_mem_manager.small)
			remove_zone_from_list(&g_mem_manager.small, zone);
		munmap(zone, zone->size + sizeof(t_mem_zone));
	}
}