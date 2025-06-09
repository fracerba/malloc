#include "malloc.h"

char *convert_to_hex(void *ptr)
{
    unsigned long long	value = (unsigned long long)ptr;
    char				hex_digits[] = "0123456789ABCDEF";
    char				buffer[2 + sizeof(void *) * 2 + 1];
    int					i = 0;

    buffer[0] = '0';
    buffer[1] = 'x';
    i = 2;

    if (value == 0)
    {
        buffer[i++] = '0';
    }
    else
    {
        char tmp[sizeof(void *) * 2];
        int j = 0;
        while (value > 0)
        {
            tmp[j++] = hex_digits[value % 16];
            value = value / 16;
        }
        while (j > 0)
            buffer[i++] = tmp[--j];
    }
    buffer[i] = '\0';
    return ft_strdup(buffer);
}

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
					char *start_str = convert_to_hex((void *)((char *)block + sizeof(t_mem_block)));
					char *end_str = convert_to_hex((void *)((char *)block + sizeof(t_mem_block) + block->size));
					ft_printf("%s - %s : %u bytes\n", start_str, end_str, (unsigned int)block->size);
					free(start_str);
					free(end_str);
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