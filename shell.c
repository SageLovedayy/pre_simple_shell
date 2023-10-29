#include <stdio.h>
#include "main.h"

int main(int argc, char *argv[])
{
	char input[BUFFER], *token, *copy;
	ssize_t bytes_read;

	(void)argc;
	(void)argv;

	while (1)
	{
		printf("#cisfun$ ");
		fflush(stdout);

		bytes_read = read(STDIN_FILENO, input, BUFFER);

		if (bytes_read == -1)
		{
			perror("read");
			exit(EXIT_FAILURE);
		}

		input[bytes_read] = '\0';

		token = strtok(input, " \n");

		while (token != NULL)
		{
			copy = strdup(token);

			free(copy);

			token = strtok(NULL, " \n");
		}
	}

	return 0;
}
