#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <sys/wait.h>

void cmdline_t(char *token, const char *path, char **params);
int empty_line(char *cmdline);
void get_no_space_str(char **argv, char **params, char *token);

char *_str_concat(char *s1, char *s2);
void str_copy(char *dest, const char *src);
int str_compare(const char *s1, const char *s2);
int strlen(char *c);
int exit_sh(char **params, char *argv);
int str_to_int(const char *str);
char *path(char *argv);
char *token_d(char *pv_cp, char *argv, char *pv);
void cmdline_t(char *token, const char *path, char **params);

#endif