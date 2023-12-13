#include "main.h"

void free_params(char **params)
{
	int i = 0;

	while (params[i] != NULL)
	{
		free(params[i]);
		i++;
	}
	free(params);
}

char **separate_params(char *input)
{
	char **tokens = NULL;
	char *token;
	int i = 0;

	token = strtok(input, " \t\n");
	while (token != NULL)
	{
		tokens = realloc(tokens, sizeof(char *) * (i + 1));
		if (tokens == NULL)
		{
			free_params(tokens);
			return (NULL);
		}

		tokens[i] = malloc(strlen(token) + 1);
		if (tokens[i] == NULL)
		{
			free_params(tokens);
			return (NULL);
		}

		strcpy(tokens[i], token);
		i++;
		token = strtok(NULL, " \t\n");
	}

	tokens = realloc(tokens, sizeof(char *) * (i + 1));
	if (tokens == NULL)
	{
		free_params(tokens);
		return (NULL);
	}
	tokens[i] = NULL;

	return (tokens);
}

void handle_command(char *command, char **params)
{
	printf("Command: %s\n", command);
	printf("Parameters:\n");
	int i = 0;

	while (params[i] != NULL)
	{
		printf("%s\n", params[i]);
		i++;
	}
}
