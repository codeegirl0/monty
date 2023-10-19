#include "monty.h"
#include "logs.h"

/**
 * getting_myfunc - get correct function
 * @myprs: bytecode line
 * Return: ponter to the function of null
 */
void (*getting_myfunc(char **myprs))(stack_t **, unsigned int)
{
	instruction_t func_arr[] = {
		{"push", handle_push},
		{"pall", handle_pall},
		{"pint", handle_pint},
		{"pop", handle_pop},
		{"swap", handle_swap},
		{"add", handle_adding},
		{"nop", handle_nop},
		{"sub", handle_subop},
		{"div", handle_divop},
		{"mod", handle_modop},
		{"mul", handle_mulop},
		{"pchar", handling_pchar},
		{"pstr", handling_pstr},
		{"rotr", handling_rotr},
		{"rotl", handling_rotl},
		{"stack", handling_stack},
		{"queue", handling_queue},
		{NULL, NULL}
	};
	int codes = 17, j;
	for (j = 0; j < codes; j++)
	{
		if (strcmp(func_arr[j].opcode, myprs[0]) == 0)
		{
			return (func_arr[j].f);
		}
	}
	return (NULL);
}

/**
 * handle_push - handling push
 * @stack: db pointer to push
 * @ln_number: file line number
 */
void handle_push(stack_t **stack, unsigned int ln_number)
{
	stack_t *new;
	int num = 0, j;

	if (data.words[1] == NULL)
	{
		dprintf(STDERR_FILENO, PUSH_FAIL, ln_number);
		everything_free(1);
		exit(EXIT_FAILURE);
	}
	for (j = 0; data.words[1][j]; j++)
	{
		if (isalpha(data.words[1][j]) != 0)
		{
			dprintf(STDERR_FILENO, PUSH_FAIL, ln_number);
			everything_free(1);
			exit(EXIT_FAILURE);
		}
	}
	num = atoi(data.words[1]);
	if (data.myqflag == 0)
		new = adding_nodeint(stack, num);
	else if (data.myqflag == 1)
		new = adding_nodeint_end(stack, num);
	if (!new)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		everything_free(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * handle_pall - handling pall
 * @stack: pointer to what push
 * @ln_number: file line number
 */
void handle_pall(stack_t **stack, unsigned int ln_number)
{
	(void)ln_number;
	if (*stack)
		printing_thelistint(*stack);
}