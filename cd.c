#include "shell.h"

/**
 * c_dir- changes the working directory.
 * @params : double pointer to the path to the new directory.
 * @argv : An array of pointers.
 */

void c_dir(char **params, char *argv)
{
	int i;
	char buffer[1024];

	for (i = 0; params[i] != NULL; i++)
	{
	}

	if (i == 1)
	{
		if (chdir("/root") == -1)
			perror("");
	}

	else if (i == 2)
	{
		if (str_compare(params[1], "-") == 0)
		{
			if (chdir("/root") == -1)
				perror(params[1]);

			return;
		}

		if (params[1][0] == '/')
		{
			if (access(params[1], F_OK) != 0)
			{
				dir_not_exist(argv, params[1]);
				return;
			}

			if (chdir(params[1]) == -1)
			{
				perror(params[1]);
			}
		}

		else
		{
			if (getcwd(buffer, sizeof(buffer)) != NULL)
			{
				abs_path(params[1], buffer);
			}

			else
			{
				perror("");
			}
		}
	}
}

/**
 * abs_path - function that returns the abs path of the user input
 * @rel_path : user input relative path
 * @cwd : current working directory
 */

void abs_path(char *relative_path, char *current_working_dir)
{
	char *new_directory;
	int i, j;

	new_directory = malloc(sizeof(char) * (strlen(current_working_dir) + str_length(relative_path + 1)));
	for (i = 0; current_working_dir[i] ; i++)
	{
		new_directory[i] = current_working_dir[i];
	}
	new_directory[i] = '/';

	for (j = 0 ; relative_path[j] ; j++)
	{
		new_directory[i + j + 1] = relative_path[j];
	}
	new_directory[i + j + 1] = '\0';
	if (chdir(new_directory) == -1)
		perror(relative_path);
	free(new_directory);
}
