#include "shell.h"

/**
 * exit_sh - Terminate the shell.
 * @params: Double pointer to an array.
 * @argv: Pointer to the executable.
 * Return: an int.
 */

int exit_sh(char **params, char *argv)
{
	int i;
	int status;

	for (i = 0; params[i] != NULL; i++)
	{
	}

	if (i == 0)
		return (0);

	if (i > 1)
	{
		perror("error");
		return (0);
	}

	if (i == 1)
	{
		status = str_to_int(params[0]);
		if (status < 0)
		{
			print_error("1: exit: Illegal number: ", argv);
			write(STDERR_FILENO, params[0], strlen(params[0]));
			write(STDERR_FILENO, "\n", 1);
			return (2);
		}
		else
			return (status);
	}
	return (0);
}

/**
 * str_to_int - Convert a string to an int.
 * @str: Pointer to the input null-terminated character array.
 * Return: On successful conversion, returns the corresponding integer value.
 * If the input string is not a valid integer representation, returns -1.
 */

int str_to_int(const char *str)
{
	int rst = 0;
	int is_neg = 0;

	if (*str == '-')
	{
		is_neg = 1;
		str++;
	}
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
		{
			rst = rst * 10 + (*str - '0');
			str++;
		}
		else
			return (-1);
	}
	if (is_neg)
		rst = -rst;
	return (rst);
}
