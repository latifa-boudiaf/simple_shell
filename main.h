#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <sys/wait.h>


void myprintf(const char *string);
void free_params(char **params);
char **separate_params(char *input);
void handle_command(char *command, char **params);

#endif
