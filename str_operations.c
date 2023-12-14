#include "shell.h"

/**
 * str_copy - Copies the contents of the 'source'
 *      string to the 'destination' string.
 *
 * @source: source string
 * @destination: destination string
 * @return: a pointer to the beginning of the copied string.
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
 * str_length - Calculates the length of a string.
 *
 * @str: Pointer to the input string.
 * @return: Length of the string.
 */
int str_length(char *c)
{
        int length = 0;

        while (*c++)
                ++length;

        return (length);
}

/**
 * str_compare - Compares two strings.
 *
 * @str1: First string for comparison.
 * @str2: Second string for comparison.
 *
 * @return: 0 if equal, negative if str1 < str2, positive if str1 > str2.
 */
int str_compare(const char *s1, const char *s2)
{
        while (*s1 == *s2 && *s1 != '\0')
        {
                s1++;
                s2++;
        }

        return (*s1 - *s2);
}

/**
 * *_str_concat - Concatenates the contents of the 'source' string to the 'destination' string.
 *
 * @source: source string
 * @destination: destination string
 * @return: a pointer to the beginning of the concatenated string.
 */
char *_str_concat(char *s1, char *s2)
{
	char *Dest;
	Dest = s1;

	while (*s1 != '\0')
	{
		s1++;
	}
	while ((*s1++ = *s2++) != '\0')
	{
	}

	return (Dest);
}
