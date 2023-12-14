#include "shell.h"
#include <string.h>
#include <errno.h>

/**
* cmdline_t - returns the command type.
* @token: command symbol.
* @path : pointer to full path of the command executable.
* @params: an array.
* Return: an integer
*/

void cmdline_t(char *token, const char *path, char **params)
{
	int i;
	pid_t pid = fork();
	char **env = environ, **args;

	if (pid == -1)
	{
		perror("fork error");
		return;
	}

	for (i = 0; params[i] ; i++)
	{
	}
	if (pid == 0)
	{
		args = malloc(sizeof(char *) * (i + 2));
		get_no_space_str(args, params, token);
		execve(path, args, env);
		exit(1);
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
	}
}
