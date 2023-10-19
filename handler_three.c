#include "monty.h"
#include "logs.h"

/**
 * handling_rotl - handling rotl
 * @stack: pointer to push stack
 * @ln_number: file line number
 */
void handling_rotl(stack_t **stack, unsigned int ln_number)
{
	stack_t *temp = *stack;
	int thenum  = 0;
	(void)ln_number;

	if (*stack == NULL)
		return;
	temp = get_node_atindex(*stack, 0);
	thenum = temp->n;
	del_node_atindex(stack, 0);
	adding_nodeint_end(stack, thenum);
}

/**
 * handling_rotr - handling rotr
 * @stack: pointer to push stack
 * @ln_number: file line number
 */
void handling_rotr(stack_t **stack, unsigned int ln_number)
{
	stack_t *temp = *stack;
	int thenum = 0, len = thelistint_len(*stack);
	(void)ln_number;

	if (*stack == NULL)
		return;
	temp = get_node_atindex(*stack, len - 1);
	thenum = temp->n;
	del_node_atindex(stack, len - 1);
	adding_nodeint(stack, thenum);
}

/**
 * handling_stack - handling stack
 * @stack: pointer to push stack
 * @ln_number: file line number
 */
void handling_stack(stack_t **stack, unsigned int ln_number)
{
	(void)stack;
	(void)ln_number;
	data.myqflag = 0;
}


/**
 * handling_queue - handling queue
 * @stack: pointer to push stack
 * @ln_number: file line number
 */
void handling_queue(stack_t **stack, unsigned int ln_number)
{
	(void)stack;
	(void)ln_number;
	data.myqflag = 1;
}