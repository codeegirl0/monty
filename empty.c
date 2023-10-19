#include "monty.h"
#include "logs.h"

/**
 * everything_free - handling memory
 * @everyth: it is a flag to free
 */
void everything_free(int everyth)
{
	if (data.line)
	{
		free(data.line);
		data.line = NULL;
		all_freeing(data.words);
		data.words = NULL;
	}
	if (everyth)
	{
		if (data.stack)
		{
			freeing_thelists(data.stack);
			data.stack = NULL;
		}
		if (data.myfptr)
		{
			fclose(data.myfptr);
			data.myfptr = NULL;
		}
	}
}