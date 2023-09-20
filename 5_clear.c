#include "main.h"
#include "shell.h"

/**
 * _clear - this function clears the terminal screen.
 * @params: these are the parameters
 *
 * Return: void
 */
void _clear(param_t *params)
{
	(void)params;
	_printf("\033[2J\033[1;1H");
}

