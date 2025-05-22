#include "malloc.h"

void free(void *ptr)
{
	if (!ptr)
		return;

	t_mem_block *block = (t_mem_block *)((char *)ptr - sizeof(t_mem_block));
	block->is_free = 1;

	// Combina blocchi liberi adiacenti
	t_mem_block *current = block;
	while (current->next && current->next->is_free)
	{
		current->size += sizeof(t_mem_block) + current->next->size;
		current->next = current->next->next;
	}

	// Se il blocco appartiene a "LARGE", rilascia la memoria
	if (block->size > SMALL_MAX)
	{
		munmap(block, block->size + sizeof(t_mem_block));
	}
}