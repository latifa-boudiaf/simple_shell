#include "shell.h"

/**
 * get_no_space_str - get no space strs.
 * @argv: A pointer to the destination array of strings.
 * @params: A pointer to the source array of strings.
 * @token: The first token to be included in the argv array.
 */

void get_no_space_str(char **argv, char **params, char *token)
{
	int argv_id = 1, i, k, j;
	int spaces;

	argv[0] = token;
	for (i = 0; params[i] != NULL; i++)
	{
		spaces = 1;
		for (j = 0; params[i][j]; j++)
		{
			if (params[i][j] != ' ' && params[i][j] != '\t')
			{
				spaces = 0;
				break;
			}
		}
		if (!spaces)
		{
			k = 0;
			argv[argv_id] = malloc(str_length(params[i]) + 1);
			for (j = 0; params[i][j]; j++)
			{
				if (params[i][j] != ' ' && params[i][j] != '\t')
				{
					argv[argv_id][k] = params[i][j];
					k++;
				}
			}
			argv[argv_id][k] = '\0';
			argv_id++;
		}
	}
	argv[argv_id] = NULL;
}

/**
 * empty_line - Checks if the input is empty line.
 * @cmdline: The user input
 * Return: 1 if it's empty line and 0 if it's not
 */

int empty_line(char *cmdline)
{
	int spaces = 1;
	int i;

	for (i = 0; cmdline[i] ; i++)
	{
		if (cmdline[i] != ' ' && cmdline[i] != '\t' && cmdline[i] != '\n')
		{
			spaces = 0;
			break;
		}
	}
	return (spaces);
}
