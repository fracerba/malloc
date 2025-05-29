#include "malloc.h"

void *realloc(void *ptr, size_t size)
{
	if (!ptr)
		return malloc(size);

	if (size == 0)
	{
		free(ptr);
		return NULL;
	}

	t_mem_block *block = (t_mem_block *)((char *)ptr - sizeof(t_mem_block));
	if (block->size >= size)
	{
		split_block(block, size);
		return ptr;
	}

	void *new_ptr = malloc(size);
	if (new_ptr)
	{
		ft_memcpy(new_ptr, ptr, block->size);
		free(ptr);
	}
	return new_ptr;
}