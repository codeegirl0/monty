#include "monty.h"
#include "logs.h"

/**
 * handle_pint - handling pint
 * @stack: pointer to push
 * @ln_number: file line number
 */
void handle_pint(stack_t **stack, unsigned int ln_number)
{
	stack_t *head = *stack;

	if (!head)
	{
		vprintf(STDERR_FILENO, PINT_FAIL, ln_number);
		everything_free(1);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", head->n);
}

/**
 * handle_pop - handling pop
 * @stack: pointer to push
 * @ln_number: file line number
 */
void handle_pop(stack_t **stack, unsigned int ln_number)
{
	stack_t *temp = *stack;

	if (!temp)
	{
		dprintf(STDERR_FILENO, POP_FAIL, ln_number);
		everything_free(1);
		exit(EXIT_FAILURE);
	}
	del_node_atindex(stack, 0);
}

/**
 * handle_swap - handling swap
 * @stack: pointer to push
 * @ln_number: file line number
 */
void handle_swap(stack_t **stack, unsigned int ln_number)
{
	stack_t *temp = *stack, *node = NULL;
	int mynum;

	if (thelistint_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, SWAP_FAIL, ln_number);
		everything_free(1);
		exit(EXIT_FAILURE);
	}
	temp = get_node_atindex(*stack, 0);
	mynum = temp->n;
	del_node_atindex(stack, 0);
	node = push_node_atindex(stack, 1, mynum);
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		everything_free(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * handle_adding - handling add
 * @stack: pointer to push
 * @ln_number: file line number
 */
void handle_adding(stack_t **stack, unsigned int ln_number)
{
	int thesum = 0;
	stack_t *node = NULL;
	stack_t *node_0 = get_node_atindex(*stack, 0);
	stack_t *node_1 = get_node_atindex(*stack, 1);

	if (thelistint_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, ADD_FAIL, ln_number);
		everything_free(1);
		exit(EXIT_FAILURE);
	}
	thesum = node_0->n + node_1->n;
	del_node_atindex(stack, 0);
	del_node_atindex(stack, 0);
	node = adding_nodeint(stack, thesum);
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		everything_free(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * handle_nop - handling nop
 * @stack: pointer to push
 * @ln_number: file line number
 */
void handle_nop(stack_t **stack, unsigned int ln_number)
{
	(void)stack;
	(void)ln_number;
}