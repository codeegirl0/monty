#include "monty.h"
#include "logs.h"

/**
 * handling_pchar - handling instrunction of pchar 
 * @stack: pointer of stack to push
 * @ln_number: file line number
 */
void handling_pchar(stack_t **stack, unsigned int ln_number)
{
	stack_t *node = *stack;

	if (!node)
	{
		dprintf(STDERR_FILENO, PCHAR_FAIL, ln_number);
		everything_free(1);
		exit(EXIT_FAILURE);
	}
	if (node->n < 0 || node->n > 127)
	{
		dprintf(STDERR_FILENO, PCHAR_RANGE, ln_number);
		everything_free(1);
		exit(EXIT_FAILURE);
	}

	putchar(node->n);
	putchar('\n');
}

/**
 * handling_pstr - to handle the instruction of pstr 
 * @stack: pointer to stack
 * @ln_number: file ine number
 */
void handling_pstr(stack_t **stack, unsigned int ln_number)
{
	stack_t *node = *stack;
	(void)ln_number;
	if (!node)
	{
		putchar('\n');
		return;
	}
	while (node && node->n != 0 && node->n >= 0 && node->n <= 127)
	{
		putchar(node->n);
		node = node->next;
	}

	putchar('\n');
}