#include "monty.h"
#include "logs.h"
#include <stdio.h>

mydata_t data = DATA_INIT;

/**
 * mymont - main function
 * @args: pointer to arg
 * Description: file opening reading and calling
 */
void mymont(myargs_t *args)
{
	size_t len = 0;
	int myget = 0;
	void (*code_func)(stack_t **, unsigned int);

	if (args->ac != 2)
	{
		dprintf(STDERR_FILENO, USAGE);
		exit(EXIT_FAILURE);
	}
	data.myfptr = fopen(args->av, "r");
	if (!data.myfptr)
	{
		dprintf(STDERR_FILENO, FILE_ERROR, args->av);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		args->ln_number++;
		myget = getline(&(data.line), &len, data.myfptr);
		if (myget < 0)
			break;
		data.words = stringtow(data.line);
		if (data.words[0] == NULL || data.words[0][0] == '#')
		{
			everything_free(0);
			continue;
		}
		code_func = getting_myfunc(data.words);
		if (!code_func)
		{
			dprintf(STDERR_FILENO, UNKNOWN, args->ln_number, data.words[0]);
			everything_free(1);
			exit(EXIT_FAILURE);
		}
		code_func(&(data.stack), args->ln_number);
		everything_free(0);
	}
	everything_free(1);
}

/**
 * main - monty entry pointe
 * @argc: num arg
 * @argv: array arg
 * Return: exit success if success or exit fail if failed
 */
int main(int argc, char *argv[])
{
	myargs_t args;
	args.av = argv[1];
	args.ac = argc;
	args.ln_number = 0;
	mymont(&args);

	return (EXIT_SUCCESS);
}