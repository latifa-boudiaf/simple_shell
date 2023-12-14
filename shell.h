#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <sys/wait.h>

extern char **environ;

void cmdline_t(char *token, const char *path, char **params);
int empty_line(char *cmdline);
void get_no_space_str(char **argv, char **params, char *token);
void dir_not_exist(char *argv, char *dir);
void error(char *msg, char *argv);
void abs_path(char *relative_path, char *current_working_dir);
void c_dir(char **params, char *argv);
void abs_path(char *relative_path, char *current_working_dir);
char *_str_concat(char *s1, char *s2);
void str_copy(char *dest, const char *src);
int str_compare(const char *s1, const char *s2);
int str_length(char *c);
int exit_sh(char **params, char *argv);
int str_to_int(const char *str);
char *_path(char *argv);
char *token_d(char *pv_cp, char *argv, char *pv);
void cmdline_t(char *token, const char *path, char **params);
void processUserInput(char **cmdline, char *argv);
char **tokenize_cmdline(char *cmdline);
void executeCommand(char *path, char **tokens, char *argv, int *status);
void deallocateDblPointer(char **dblpointer, int len);

#endif
