#include "shell.h"

/**
 * str_length- returns the lenght of a string.
 * @c: the pointer to the first character of the string.
 * Return: length of the given string
 */

int str_length(char *c)
{
	int i;

	for (i = 0 ; *c != '\0'; c++)
		++i;
	return (i);
}

/**
 * str_compare- it compares two strings.
 * @s1: first string.
 * @s2: second string.
 * Return: a positive number if the first string comes first,
 * 0 if they are equal
 * and a negative number if the second string comes first.
 */

int str_compare(const char *s1, const char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		return (0);
		 s1++;
		 s2++;
	}

	if (*s1 > *s2)
		return (*s1 - *s2);
	else
		return (*s2 - *s1);
}

/**
 * str_copy - copies a string from a source to a destination.
 * @dest: destination string
 * @src: source string
 * Return: void.
 */

void str_copy(char *dest, const char *src)
{
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}

/**
 * _str_concat- concatenates two strings.
 * @s1: firts string.
 * @s2: second string.
 * Return: concatenated string.
 */

char *_str_concat(char *s1, char *s2)
{
	int i = 0;
	int j = 0;

	while (s1[i])
		i++;
	for (j = 0; s2[j]; j++)
		s1[i++] = s2[j];
	s1[i] = '\0';
	return (s1);
}
