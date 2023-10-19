#include "monty.h"
#include "logs.h"

/**
 * handle_subop - handling sub
 * @stack: pointer to the push
 * @ln_number: file line number
 */
void handle_subop(stack_t **stack, unsigned int ln_number)
{
	int thesub = 0;
	stack_t *node = NULL;
	stack_t *node_0 = get_node_atindex(*stack, 0);
	stack_t *node_1 = get_node_atindex(*stack, 1);

	if (thelistint_len(*stack) < 2)
	{
		vprintf(STDERR_FILENO, SUB_FAIL, ln_number);
		everything_free(1);
		exit(EXIT_FAILURE);
	}
	thesub = node_1->n - node_0->n;
	del_node_atindex(stack, 0);
	del_node_atindex(stack, 0);
	node = adding_nodeint(stack, thesub);
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		everything_free(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * handle_divop - handling div
 * @stack: pointer to the push
 * @ln_number: file line number
 */
void handle_divop(stack_t **stack, unsigned int ln_number)
{
	int thediv = 0;
	stack_t *node = NULL;
	stack_t *node_0 = get_node_atindex(*stack, 0);
	stack_t *node_1 = get_node_atindex(*stack, 1);

	if (thelistint_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, DIV_FAIL, ln_number);
		everything_free(1);
		exit(EXIT_FAILURE);
	}
	if (node_0->n == 0)
	{
		dprintf(STDERR_FILENO, DIV_ZERO, ln_number);
		everything_free(1);
		exit(EXIT_FAILURE);
	}
	thediv = node_1->n / node_0->n;
	del_node_atindex(stack, 0);
	del_node_atindex(stack, 0);
	node = adding_nodeint(stack, thediv);
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		everything_free(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * handle_mulop - handling mul
 * @stack: pointer to the push
 * @ln_number: file line number
 */
void handle_mulop(stack_t **stack, unsigned int ln_number)
{
	int themul = 0;
	stack_t *node = NULL;
	stack_t *node_0 = get_node_atindex(*stack, 0);
	stack_t *node_1 = get_node_atindex(*stack, 1);

	if (thelistint_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, MUL_FAIL, ln_number);
		everything_free(1);
		exit(EXIT_FAILURE);
	}
	themul = node_1->n * node_0->n;
	del_node_atindex(stack, 0);
	del_node_atindex(stack, 0);
	node = adding_nodeint(stack, themul);
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		everything_free(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * handle_modop - handling mod
 * @stack: pointer to the push
 * @ln_number: file line number
 */
void handle_modop(stack_t **stack, unsigned int ln_number)
{
	int themod = 0;
	stack_t *node = NULL;
	stack_t *node_0 = get_node_atindex(*stack, 0);
	stack_t *node_1 = get_node_atindex(*stack, 1);

	if (thelistint_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, MOD_FAIL, ln_number);
		everything_free(1);
		exit(EXIT_FAILURE);
	}
	if (node_0->n == 0)
	{
		dprintf(STDERR_FILENO, DIV_ZERO, ln_number);
		everything_free(1);
		exit(EXIT_FAILURE);
	}
	themod = node_1->n % node_0->n;
	del_node_atindex(stack, 0);
	del_node_atindex(stack, 0);
	node = adding_nodeint(stack, themod);
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		everything_free(1);
		exit(EXIT_FAILURE);
	}
}