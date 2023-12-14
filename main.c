#include "shell.h"

/**
 * main - Entry point to the program
 * @argc: The number of command-line arguments
 * @argv: An array of pointers to the command-line arguments
 * Return: 0 (Success)
 */

int main(int argc, char *argv[])
{
	char *cmdline;
        size_t size = 0;
	ssize_t err = 0;

	(void)argc;
	while (1)
	{
		cmdline = NULL;

		err = getline(&cmdline, &size, stdin);

		if (err == -1)
		{
			free(cmdline);
			exit(0);
		}

		processUserInput(&cmdline, argv[0]);
		free(cmdline);
	}
	return (0);
}
