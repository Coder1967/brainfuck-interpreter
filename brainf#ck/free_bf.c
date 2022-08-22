#include "bf.h"
/**
 * free_bf - frees all allocated memory
 */
void free_bf()
{
	if (bf.array != NULL)
	{
		free(bf.array);
		bf.array = NULL;
	}
	if (bf.str != NULL)
	{
		free(bf.str);
		bf.str = NULL;
	}
}
