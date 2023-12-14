#include "shell.h"
/**
 * _path - function that searches for the executable path of a command
 * @argv: The command to search for.
 * Return: The path to the executable, or NULL if not found.
 */
char *_path(char *argv)
{
	char **env = environ;
	char *exe_path = NULL, first_token[6];
	char *pv, *pv_cp;
	int i, j;

	for (i = 0; env[i] != NULL; i++)
	{
		for (j = 0; j < 5; j++)
			first_token[j] = env[i][j];
		first_token[j] = '\0';

		if (str_compare(first_token, "PATH=") == 0)
		{
			pv = malloc(sizeof(char) * (str_length(env[i]) - 4));
			pv_cp = malloc(sizeof(char) * (str_length(env[i]) - 4));
			if (pv_cp == NULL)
			{
				free(pv);
				return (NULL);
			}
			if (pv == NULL)
			{
				free(pv_cp);
				return (NULL);
			}
			str_copy(pv, env[i] + 5);
			str_copy(pv_cp, pv);
			exe_path = token_d(pv_cp, argv, pv);
			return (exe_path);
		}
	}
	return (NULL);
}

/**
 * token_dirs -function that tokenizes & searches directories for an executable
 * @pv_cp: a copy of the PATH environment variable.
 * @argv: The command to search for.
 * @pv: The original PATH environment variable.
 *
 * Return: The path to the executable, or NULL if not found.
 */

char *token_d(char *pv_cp, char *argv, char *pv)
{
	char *exe_path = NULL, *path_dir;

	path_dir = strtok(pv_cp, ":;");
	while (path_dir != NULL)
	{
		exe_path = malloc(str_length(path_dir) + str_length(argv) + 2);
		if (exe_path == NULL)
		{
			free(pv);
			free(pv_cp);
			return (NULL);
		}
		str_copy(exe_path, path_dir);
		_str_concat(exe_path, "/");
		_str_concat(exe_path, argv);
		if (access(exe_path, F_OK | X_OK) == 0)
		{
			free(pv);
			free(pv_cp);
			return (exe_path);
		}
		free(exe_path);
		path_dir = strtok(NULL, ":;");
	}
	free(pv);
	free(pv_cp);
	return (NULL);
}
