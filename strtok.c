#include <stdlib.h>
#include "shell.h"
#include "main.h"
/**
 * isDelim - Determine whether a character is among the delimiters
 * @c: is the character
 * @delim: it is delimeters
 *
 * Return: Returns 1 if it's a delimiter, or 0 otherwise
 */
int isDelim(char c, char *delim)
{
	while (*delim)
	{
		if (c == *delim)
			return (1);
		delim++;
	}
	return (0);
}
/**
 * _strtok - strtok_r
 * @str: is the string to be passed
 * @delim: is delimiters for tokens
 * @savePtr: state
 *
 * Return: next token found in string, NULL if not found
 */
char *_strtok(char *str, char *delim, char **savePtr)
{
	char *ptr, *modify, *end;
	int quoteFound = 0;

	if (*savePtr)
		ptr = *savePtr;
	else
		ptr = str;
	end = ptr;
	while (*end)
		end++;
	while (*ptr && isDelim(*ptr, delim))
		ptr++;
	modify = ptr;
	if (*ptr == '\0')
	{
		return (NULL);
	}
	if (*ptr == '\'')
	{
		ptr++;
		modify = _strchr(ptr, '\'');
		if (!modify)
		{
			_printf("no exact quote found!\n");
			exit(-1);
		}
		*modify = '\0';
		*savePtr = modify + 1;
		return (_strdup(ptr));
	}
	while (*modify)
	{
		if (*modify == '\'')
			quoteFound = 1;
		if (isDelim(*modify, delim) && quoteFound == 0)
			break;
		modify++;
	}
	if (*modify == '\0')
		*savePtr = modify;
	else
		*savePtr = modify + 1;
	*modify = '\0';
	return (_strdup(ptr));
}
