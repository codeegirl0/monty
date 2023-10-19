#include "monty.h"
#include "logs.h"

/**
 * word_counting - count num string
 * @s: valuated string
 * Return: word char  number
 */
int word_counting(char *s)
{
	int flag, b, v;
	flag = 0;
	v = 0;

	for (b = 0; s[b] != '\0'; b++)
	{
		if (s[b] == ' ')
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			v++;
		}
	}

	return (v);
}
/**
 * **stringtow - cutting string to words
 * @str: the string to be splited
 * Return: pointer to the array of strings if success
 * or NULL in fail
 */
char **stringtow(char *str)
{
	char **matrix, *tmp;
	int j, k = 0, len = 0, words, p = 0, start, end;
	len = strlen(str);
	words = word_counting(str);
	if (words == 0)
		return (NULL);
	matrix = (char **) malloc(sizeof(char *) * (words + 1));
	if (matrix == NULL)
		return (NULL);
	for (j = 0; j <= len; j++)
	{
		if (isspace(str[j]) || str[j] == '\0' || str[j] == '\n')
		{
			if (p)
			{
				end = j;
				tmp = (char *) malloc(sizeof(char) * (p + 1));
				if (tmp == NULL)
					return (NULL);
				while (start < end)
					*tmp++ = str[start++];
				*tmp = '\0';
				matrix[k] = tmp - p;
				k++;
				p = 0;
			}
		}
		else if (p++ == 0)
			start = j;
	}

	matrix[k] = NULL;

	return (matrix);
}

/**
 * all_freeing - make empty array string
 * @args: freeable array strings
 */
void all_freeing(char **args)
{
	int j;

	if (!args)
		return;

	for (j = 0; args[j]; j++)
		free(args[j]);

	free(args);
}