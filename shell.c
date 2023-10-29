#include <stdio.h>
#include "main.h"

void argChecker(char *cmd)
{
	BuiltInCommand builtInCommands[] = {
	    {"env", handleEnvCommand},
	    /* Add more built-in commands */
	};
	size_t i;
	char *token = strtok(cmd, " ");
	if (token != NULL)
	{
		for (i = 0; i < sizeof(builtInCommands) / sizeof(builtInCommands[0]); i++)
		{
			if (strcmp(token, builtInCommands[i].name) == 0)
			{
				builtInCommands[i].func(token);
				return;
			}
		}
		/* If the command is not a built-in command, we'll handle external commands here */
		printf("We only accept few Built-in for now :D\n");
	}
}

int main(int argc, char *argv[])
{
	char *input = NULL;
	ssize_t bytes_read;
	size_t input_size = 0;

	(void)argc;
	(void)argv;

	while (1)
	{
		printf("#cisfun$ ");
		fflush(stdout);


		bytes_read = getline(&input, &input_size, stdin);
		if (bytes_read == -1)
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}
		/* Remove trailing newline */
		input[bytes_read - 1] = '\0';

		argChecker(input);
	}

	free(input);
	return 0;
}
