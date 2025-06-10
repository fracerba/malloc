#include "malloc.h"

size_t get_page_size(void)
{
	return sysconf(_SC_PAGESIZE);
}

t_mem_zone *create_zone(size_t block_size, size_t num_blocks)
{
	size_t page_size = get_page_size();
	size_t zone_size = (block_size * num_blocks) + sizeof(t_mem_zone);

	// Allinea la dimensione della zona alla dimensione della pagina
	zone_size = ((zone_size + page_size - 1) / page_size) * page_size;

	t_mem_zone *zone = mmap(NULL, zone_size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	if (zone == MAP_FAILED)
		return NULL;

	zone->start = (void *)zone + sizeof(t_mem_zone);
	zone->size = zone_size - sizeof(t_mem_zone);
	zone->blocks = NULL;
	zone->next = NULL;

	return zone;
}

t_mem_block *find_free_block(t_mem_zone *zone, size_t size)
{
	t_mem_block *current = zone->blocks;
	while (current)
	{
		if (current->is_free && current->size >= size)
			return current;
		current = current->next;
	}
	return NULL;
}

void split_block(t_mem_block *block, size_t size)
{
	if (block->size > size + sizeof(t_mem_block))
	{
		t_mem_block *new_block = (void *)block + sizeof(t_mem_block) + size;
		new_block->size = block->size - size - sizeof(t_mem_block);
		new_block->is_free = 1;
		new_block->next = block->next;

		block->size = size;
		block->next = new_block;
	}
}

void remove_zone_from_list(t_mem_zone **head, t_mem_zone *to_remove)
{
	if (!head || !*head || !to_remove)
		return;
	if (*head == to_remove)
	{
		*head = to_remove->next;
		return;
	}
	t_mem_zone *prev = *head;
	t_mem_zone *curr = (*head)->next;
	while (curr)
	{
		if (curr == to_remove)
		{
			prev->next = curr->next;
			return;
		}
		prev = curr;
		curr = curr->next;
	}
}