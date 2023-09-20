#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

#define BUFFER_SIZE 1024

int flush_buffer(char *buffer, int *index);

int print_arg(char *arg);

void get_type(char *format, int *index);
/**
 * _printf - Print text to the standard output
 * using the specified format
 * @format: instructions for printing text.
 *
 * Return:  count of characters that have been printed
 */
int _printf(const char *format, ...)
{
	int higher, sum = 0, index = 0;
	char *arg = NULL;
	char buffer[BUFFER_SIZE] = {0};
	va_list params;

	if (!format)
		return (-1);
	/* special case only one % sign */
	if (_strlen((char *)format) == 1 && format[0] == '%')
	{
		return (-1);
	}
	higher = 0;
	va_start(params, format);
	while (1)
	{
		if (index == BUFFER_SIZE)
		{
			sum += flush_buffer(buffer, &index);
		}
		if (format[higher] == '%')
		{
			get_type((char *)format, &higher);
			switch (format[higher])
			{
			case 'c':
				buffer[index] = (char) va_arg(params, int);
				index++;
				higher++;
				continue;
			case 's':
				arg = get_arg('s', va_arg(params, char*));
				break;
			case 'd':
			case 'i':
				arg = get_arg('d', va_arg(params, int));
				break;
			case 'b':
				arg = get_arg('b', va_arg(params, int));
				break;
			case 'r':
				arg = get_arg('r', va_arg(params, char *));
				break;
			case 'R':
				arg = get_arg('R', va_arg(params, char *));
				break;
			case '%':
				arg = malloc(2);
				arg[0] = '%';
				arg[1] = '\0';
				break;
			case '\0':
				buffer[index] = '%';
				index++;
				continue;
			default:/* unknown specifier */
				arg = malloc(3);
				arg[0] = '%';
				arg[1] = format[higher];
				arg[2] = '\0';
			}
			if (!arg)
			{
				va_end(params);
				free(arg);
				return (-1);
			}
			sum += flush_buffer(buffer, &index);
			sum += print_arg(arg);
			free(arg);
			higher++;
		}
		else if (format[higher] != '\0')
		{
			buffer[index] = format[higher];
			index++;
			higher++;
		}
		else
		{
			sum += flush_buffer(buffer, &index);
			va_end(params);
			return (sum);
		}
	}
	return (sum);
}
/**
 * flush_buffer - Output the buffer content up to a specified index
 * and then reset it
 * @buffer: is the buffer string
 * @index: index
 *
 * Return: cumulative count of characters that have been output
 */
int flush_buffer(char *buffer, int *index)
{
	int num = 0;

	num = write(1, buffer, *index);
	*index = BUFFER_SIZE - 1;
	while (*index >= 0)
	{
		buffer[*index] = 0;
		*index -= 1;
	}
	*index = 0;
	return (num);
}
/**
 * print_arg - display argument string
 * @arg: string
 *
 * Return: total count of bytes printed
 */
int print_arg(char *arg)
{
	return (write(1, arg, _strlen(arg)));
}
/**
 * get_type - Retrieve the data type based on the specifier
 * found in the format string
 * This function skip spaces, locates a specifier
 * and positions the index at the specifier
 * @format: is the format string
 * @index: The present position within the format string
 */
void get_type(char *format, int *index)
{
	do {
		*index += 1;
	} while (format[*index] == ' ');
}
