#include "shell.h"

/**
* processUserInput - function that takes user input and handles commands
*
* @cmdline: user input string to be processed
* @argv : An array of pointers to the command-line arguments
*/
void processUserInput(char **cmdline, char *argv)
{
	char **cmdTokens;
	char **tags;
	int i;
	int j;
	int status = 0;

	if (empty_line(*cmdline) == 1)
	{
		return;
	}

	i = 0;
	while (cmdline[i])
	{
		i++;
	}

	cmdTokens = tokenize_cmdline(*cmdline);

        i = 0;
        while (cmdTokens[i] != NULL)
        {
                i++;
        }

	tags = malloc(sizeof(char *) * i);

	if (tags == NULL)
	{
		for (i = 0; cmdTokens[i] != NULL; i++)
		{
			free(cmdTokens[i]);
		}
		free(cmdTokens);

		return;
	}

	for (j = 0; j < i - 1 ; j++)
	{
		tags[j] = malloc(str_length(cmdTokens[j + 1]) + 1);
		str_copy(tags[j], cmdTokens[j + 1]);
	}

	tags[j] = NULL;
	executeCommand(cmdTokens[0], tags, argv, &status);

	if (str_compare(cmdTokens[0], "exit") == 0)
	{
		deallocateDblPointer(cmdTokens, i);
		deallocateDblPointer(tags, i - 1);
		free(*cmdline);
		exit(status);
	}
	deallocateDblPointer(cmdTokens, i);
	deallocateDblPointer(tags, i - 1);
}
/**
 * tokenize_cmdline - Function that tokenizes the input string into parameters
 *
 *
 * @input: user input
 * @return: char double array of params
*/
char **tokenize_cmdline(char *cmdline)
{
	char **toks;
        char *tok;
	char *oneToken;
	char *input;
	int i;
	int j;

	i = 0;
	input = malloc(sizeof(char) * (str_length(cmdline)));

	if (input == NULL)
		return (NULL);

	strtok(input, "\n");
	str_copy(input, cmdline);
	tok = strtok(input, " ");

	while (tok != NULL)
	{
		i++;
		tok = strtok(NULL, " ");
	}

	toks = (char **) malloc(sizeof(char *) * (i + 1));

	if (toks == NULL)
	{
		free(input);
		return (NULL);
	}
	oneToken = strtok(cmdline, " \t");

	i = 0;
	while (oneToken != NULL)
	{
		toks[i] = malloc(str_length(oneToken) + 1);

		if (toks[i] == NULL)
		{
			for (j = 0; j < i ; j++)
				free(toks[j]);
			free(toks);
			free(input);
			return (NULL);
		}

		str_copy(toks[i], oneToken);

		oneToken = strtok(NULL, " \t");
		i++;
	}

	toks[i] = NULL;
	free(input);
	return (toks);
}
/**
 * executeCommand - Function that processes the command based on the given path.
 * @path: The path containing the command to be processed.
 * @params: the params excluding the command
 * @argv : An array of pointers to the command-line arguments
 * @status : status of the code
*/
void executeCommand(char *path, char **tokens, char *argv, int *status)
{
	char *cmdline;
        char *getCmd;
	char *fullPath;
	char *tmpPath;

	if (str_compare(path, "exit") == 0)
	{
		*status = exit_sh(tokens, argv);
		return;
	}
	if (str_compare(path, "cd") == 0)
	{
		c_dir(tokens, argv);
		return;
	}
	if (path[0] != '/')
	{
		fullPath = _path(path);
		if (fullPath == NULL)
		{
			error("1: ", argv);
			write(STDERR_FILENO, path, str_length(path));
			write(STDERR_FILENO, ": not found\n", 12);
			free(fullPath);
			*status = 127;
		}
			cmdline_t(path, fullPath, tokens);
		free(fullPath);
		return;
	}

	tmpPath = (char *)malloc(str_length(path) + 1);
	str_copy(tmpPath, path);

	if (access(path, F_OK) == 0)
	{
		getCmd = strtok(path, "/");

		while (getCmd != NULL)
		{
			cmdline = getCmd;
			getCmd = strtok(NULL, "/");
		}

		cmdline_t(cmdline, tmpPath, tokens);
	}

	free(tmpPath);
}
/**
 * deallocateDblPointer - Frees memory allocated for
 * 	a double pointer and its content.
 * @doublePtr: The double pointer to be freed.
 * @length: The length of the array of pointers.
 */
void deallocateDblPointer(char **dblpointer, int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		free(dblpointer[i]);
	}

	free(dblpointer);
}
