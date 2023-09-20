#include <stdlib.h>
#include "shell.h"
#include "main.h"
#include "lists.h"
/**
 * _alias - this is the funct to Implement alias shell command.
 * @params: this is the Ptr to a param_t struct with the shell state and arguement.
 *
 * The funct define new aliases or prints existing aliases in the shell.
 * If the funct is  called with no args, it prints all existing aliases.
 * Otherwise if called with args, assumes each arg is an alias name or def
 * and performs the appropriate action.
 */
void _alias(param_t *params)
{
	unsigned int i;

	if (params->tokCount == 1)
	{
		
		print_all_aliases(params);
		return;
	}
	for (i = 1; i < params->tokCount; i++)
	{
		if (_strchr(params->args[i], '='))
			set_alias(params->args[i], params);
		else
			print_alias(params->args[i], params);
	}
}

/**
 * set_alias - this funct create a new alias or updates an existing alias.
 * @name: this is the name of the alias to set,
 * @params: shell state
 *
 * This function sets a new alias or updates an existing one in the shell.
 *
 * Return: void
 */
void set_alias(char *name, param_t *params)
{
	char *valu, *tmp = NULL;
	unsigned int i = 0, j = 1;

	while (name[i] && name[i] != '=')
		i++;
	if (name[i + 1] == '\'')
	{
		if (_strchr(&name[i + 2], '\''))
		{
			tmp = _strchr(&name[i + 2], '\'');
			*tmp = '\0';
			valu = _strdup(&name[i + 2]);
			if (tmp[1] != '\0')
			{
				while (tmp[j] &&
					(tmp[j] == ' ' || tmp[j] == '\t' || tmp[j] == '\n'))
					j++;
				if (tmp[j] != '\0')
					set_alias(&tmp[j], params);
			}
		}
		else
		{
			_printf("Usage: alias name='value' [...]\n");
			return;
		}
	}
	else
		valu = _strdup(&name[i + 1]);
	name[i] = '\0'; /* this line sets = to terminater */
	make_alias(name, valu, params);
}

/**
 * make_alias - this is the funct to create a new alias and add to alias list.
 * @name: this is the name of the alias.,
 * @val: the value of the alias
 * @params: parameter struct containing the alias list
 *
 * This func creates a new alias using the given name and value,
 * and add to the alias list stored in the param struct.
 */

void make_alias(char *name, char *val, param_t *params)
{
	list_t *h = params->alias_head;

	while (h)
	{
		if (!_strcmp(name, h->str))
		{
			free(h->val);
			h->val = val;
			h->valLen = _strlen(val);
			params->status = 0;
			return;
		}
		h = h->next;
	}
	/* this is the env variable DNE */

	params->alias_head = add_node(&(params->alias_head), name, val);
	free(val);
	params->status = 0;
}
