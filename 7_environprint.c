#include "main.h"
#include "lists.h"
#include "shell.h"

/**
 * _printenv - this funct prints the environ.
 * @params: params
 *
 * the funct Prints all the environ vars stored in params->env_head.
 * If no environ vars exist, prints an error message.
 *
 * Return: void
 */

void _printenv(param_t *params)
{
	if (params->tokCount != 1)
	{
		_printf("env: %s: No such file or directory\n",
			params->args[1]);
		params->status = 2;
		return;
	}
	print_list_env(params->env_head);
	params->status = 0;
}

/**
 * print_list_env - this function prints the environ vars
 * @head: points to the head of the environment list.,
 *
 * The funct takes in a pointer to the head of the environment list and
 * recursively prints the list in reverse order. For each node in the list,

*/
void print_list_env(list_t *head)
{
	if (head)
	{
		print_list_env(head->next);
		if (head->str)
			_printf("%s=%s\n", head->str, head->val);
	}
}
