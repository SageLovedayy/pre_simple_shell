#ifndef _MAIN_H_
#define _MAIN_H_

#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER 1024

typedef struct {
	/* Name of the built-in command */
	const char *name;
	/* Function pointer for handling the command */
	void (*func)(char *arg);
} BuiltInCommand;

void handleEnvCommand(char *arg);

#endif /* _MAIN_H_ */