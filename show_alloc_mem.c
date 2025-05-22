#include "malloc.h"

void show_alloc_mem(void)
{
	size_t total = 0;

	t_mem_zone *zones[] = {g_mem_manager.tiny, g_mem_manager.small, g_mem_manager.large};
	const char *zone_names[] = {"TINY", "SMALL", "LARGE"};

	for (int i = 0; i < 3; i++)
	{
		t_mem_zone *zone = zones[i];
		if (zone)
			ft_printf("%s : %p\n", zone_names[i], zone->start);
		while (zone)
		{
			t_mem_block *block = zone->blocks;
			while (block)
			{
				if (!block->is_free)
				{
					// Stampa gli indirizzi come puntatori e la dimensione come unsigned int
					ft_printf("%p - %p : %u bytes\n",
						(void *)((char *)block + sizeof(t_mem_block)),
						(void *)((char *)block + sizeof(t_mem_block) + block->size),
						(unsigned int)block->size);
					total += block->size;
				}
				block = block->next;
			}
			zone = zone->next;
		}
	}
	// Stampa il totale come unsigned int
	ft_printf("Total : %u bytes\n", (unsigned int)total);
}