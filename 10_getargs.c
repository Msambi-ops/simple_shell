#include "main.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * get_arg - this funct Returns a formatted args based on the type specifier.
 *
 * @type: Type specifier indicating the desired formatting
 * @...: Var no. of args depending on the type specifier.
 *
 * This funct takes a type specifier and a var no. of args and
 * a formatted string representation of the args based on the typ specifie
 *
 * Return: A dynamically allocated string rep. of the argument based
 *        on the type specifier,
 *         or NULL if an unsupported type specifier is provided.
 */


char *get_arg(char type, ...)
{
	va_list params;

	va_start(params, type);
	switch (type)
	{
	case 'c':
		return (get_char(va_arg(params, int)));
	case 's':
		return (get_string(va_arg(params, char*)));
	case 'd':
	case 'i':
		return (get_number(va_arg(params, int)));
	case 'b':
		return (get_binary(va_arg(params, int)));
	case 'r':
		return (get_rev(va_arg(params, char *)));
	case 'R':
		return (get_rot13(va_arg(params, char *)));
	default:
		return (NULL);/* Error */
	}
}
