#include "main.h"
#include "lists.h"
#include "shell.h"
#include <stdlib.h>

/**
 * _getenv - this funct Gets the val of an environ var.
 * @name: The name of the environ var to retrieve.
 * @params: Points to the param struct containing the envirn list.
 *
 * Return: returns A ptr to the val of the environ var or NULL if not.
 *
 * This funct searches for an environ var with the givn name in the
 * linked list of environ vars contained in the param struct.
 */

char *_getenv(char *name, param_t *params)
{
	list_t *ptr = params->env_head;

	while (ptr)
	{
		if (!_strcmp(name, ptr->str))
			return (_strdup(ptr->val));
		ptr = ptr->next;
	}
	return (NULL);
}
