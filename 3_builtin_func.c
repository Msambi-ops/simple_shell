#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"
#include "lists.h"
#include "main.h"

/**
 * get_builtin - this is the fucnt to find built-in function
 * @params: this Points to the param_t struct containing command params.
 *
 * Description: Looks for a built-in funct regarding the 1st  args
 * in the param_t struct. Returns a funct ptr to the
 * built-in function if found, or NULL if not found.
 *
 * Return: returns Funct ptr to the built-in funct, NULL if not found.
 */

void (*get_builtin(param_t *params))(param_t *)
{
	op_t ops[] = {
		{"exit", _myExit},
		{"clear", _clear},
		{"env", _printenv},
		{"setenv", _setenv},
		{"cd", _cd},
		{"unsetenv", _unsetenv},
		{"alias", _alias},
		{NULL, NULL},
	};
	op_t *op = ops;

	while (op->name)
	{
		if (!_strcmp(params->args[0], op->name))
			return (op->func);
		op++;
	}
	return (NULL);
}
