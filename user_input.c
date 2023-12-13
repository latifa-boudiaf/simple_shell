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

int main(void)
{
	char input[100];

	while (1)
	{
		printf("#cisfun$ ");
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			printf("\n");
			break;
		}

		size_t len = strlen(input);
		if (len > 0 && input[len - 1] == '\n')
		{
			input[len - 1] = '\0';
		}

		if (strcmp(input, "exit") == 0)
		{
			break;
		}
		else if (strcmp(input, "") == 0)
		{
			continue;
		}

		char **params = separate_params(input);
		if (params == NULL)
		{
			perror("Allocation Error");
			return (EXIT_FAILURE);
		}

		handle_command(params[0], params);

		free_params(params);
	}

	return (0);
}
