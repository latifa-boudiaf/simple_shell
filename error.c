#include "shell.h"

/**
 * error - print an error.
 * @msg: pointer to the error message to be printed.
 * @argv: pointer to the name of the command.
 */

void error(char *msg, char *argv)
{
	write(STDERR_FILENO, argv, strlen(argv));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, msg, strlen(msg));
}

/**
 * dir_not_exist- prints an error message when dir does not exist.
 * @argv: the name of the command.
 * @dir: name of the directory.
 */

void dir_not_exist(char *argv, char *dir)
{
	error("1: cd: can't cd to ", argv);
	write(STDERR_FILENO, dir, str_len(dir));
	write(STDERR_FILENO, "\n", 1);
}
