#include "main.h"
#include <stdlib.h>

/**
 * rev_string - this funct Reverses the order of chars in a str.
 * @s: A points to a null-terminated string to be reversed.
 */
void rev_string(char *s)
{
	int head, tail;
	int length;
	char temp;

	if (s == NULL)
	{
		s = "(null)";
	}
	for (length = 0; s[length] != '\0'; length++)
		;
	head = 0;
	tail = length - 1;
	while (head < tail)
	{
		temp = *(s + head);
		*(s + head) = *(s + tail);
		*(s + tail) = temp;
		head++;
		tail--;
	}
}

/**
 * get_rev - this funct returns a reversed copy of a string
 * @s: string to be reversed,.
 * Return: the funct returns string reversed
 */
char *get_rev(char *s)
{
	char *ptr = NULL;

	ptr = get_string(s);
	if (!ptr)
	{
		return (NULL);
	}
	if (s)
	{
		rev_string(ptr);
	}
	return (ptr);
}

/**
 * rot13 - the function performs rot13 encryption on a string
 * @s: this is the string to be encrypted
 *
 * Return: returns a pointer to the encrypted string
 */
char *rot13(char *s)
{
	char *ptr;
	int i;
	char c[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
			'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
			'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G',
			'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
			'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	char r[] = {'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
			'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
			'j', 'k', 'l', 'm', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
			'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E',
			'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M'};
	for (ptr = s; *ptr != '\0'; ptr++)
	{
		for (i = 0; i < 52; i++)
		{
			if (*ptr == c[i])
			{
				*ptr = r[i];
				break;
			}
		}
	}
	return (s);
}

/**
 * get_rot13 - get rot13
 * @s: string
 * Return: returns a pointer to string
 */
char *get_rot13(char *s)
{
	char *ptr = NULL;

	ptr = get_string(s);
	if (!ptr)
		return (NULL);
	if (s)
	{
		rot13(ptr);
	}
	return (ptr);
}
