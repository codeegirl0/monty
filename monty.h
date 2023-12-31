#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int ln_number);
} instruction_t;

/**
 * struct myargs_s - structure of main
 * @av: command line file name
 * @ac: main arg numbers
 * @ln_number: ncurrent line number
 * Description: command line passing arguments
 */
typedef struct myargs_s
{
	char *av;
	int ac;
	unsigned int ln_number;
} myargs_t;

/**
 * struct mydata_s - extr data to be accessible in functions
 * @line: line of file
 * @words: line parse
 * @stack: pointer for stack
 * @myfptr: pointer of ptr
 * @myqflag: flags of stack and queue
 */
typedef struct mydata_s
{
	char *line;
	char **words;
	stack_t *stack;
	FILE *myfptr;
	int myqflag;
} mydata_t;

typedef stack_t listint_t;

extern mydata_t data;

#define DATA_INIT {NULL, NULL, NULL, NULL, 0}

#define USAGE "USAGE: monty file\n"
#define FILE_ERROR "Error: Can't open file %s\n"
#define UNKNOWN "L%u: unknown instruction %s\n"
#define MALLOC_FAIL "Error: malloc failed\n"
#define PUSH_FAIL "L%u: usage: push integer\n"
#define PINT_FAIL "L%u: can't pint, stack empty\n"
#define POP_FAIL "L%u: can't pop an empty stack\n"
#define SWAP_FAIL "L%u: can't swap, stack too short\n"
#define ADD_FAIL "L%u: can't add, stack too short\n"
#define SUB_FAIL "L%u: can't sub, stack too short\n"
#define DIV_FAIL "L%u: can't div, stack too short\n"
#define DIV_ZERO "L%u: division by zero\n"
#define MUL_FAIL "L%u: can't mul, stack too short\n"
#define MOD_FAIL "L%u: can't mod, stack too short\n"
#define PCHAR_FAIL "L%u: can't pchar, stack empty\n"
#define PCHAR_RANGE "L%u: can't pchar, value out of range\n"

/* main.c */
void mymont(myargs_t *args);

/* take_fun.c */
void (*getting_myfunc(char **myprs))(stack_t **, unsigned int);
void handle_pall(stack_t **stack, unsigned int ln_number);
void handle_push(stack_t **stack, unsigned int ln_number);

/* handler_one.c */
void handle_pint(stack_t **stack, unsigned int ln_number);
void handle_pop(stack_t **stack, unsigned int ln_number);
void handle_adding(stack_t **stack, unsigned int ln_number);
void handle_swap(stack_t **stack, unsigned int ln_number);
void handle_nop(stack_t **stack, unsigned int ln_number);

/* handler_two.c */
void handle_subop(stack_t **stack, unsigned int ln_number);
void handle_divop(stack_t **stack, unsigned int ln_number);
void handle_modop(stack_t **stack, unsigned int ln_number);
void handle_mulop(stack_t **stack, unsigned int ln_number);

/* handler_three.c */
void handling_rotl(stack_t **stack, unsigned int ln_number);
void handling_rotr(stack_t **stack, unsigned int ln_number);
void handling_queue(stack_t **stack, unsigned int ln_number);
void handling_stack(stack_t **stack, unsigned int ln_number);

/* letters.c */
void handling_pchar(stack_t **stack, unsigned int ln_number);
void handling_pstr(stack_t **stack, unsigned int ln_number);

/* empty.c */
void everything_free(int everyth);

/* stringtow.c */
int word_counting(char *s);
char **stringtow(char *str);
void all_freeing(char **args);


#endif