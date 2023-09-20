#include <stdlib.h>
#include "shell.h"
#include "main.h"
#include "lists.h"

/**
 * print_alias - this funct prints the val of an alias, if it exists.,
 * @name: this is the name of the alias to print.
 * @params: param struct containing the alias list.,
 * This function searches the alias list stored in the parameter struct  alias.
*/
void print_alias(char *name, param_t *params)
{
	unsigned int length = 0;
	list_t *ptr = params->alias_head;

	length = _strlen(name);
	while (ptr)
	{
		if (_strcmp_n(name, ptr->str, length - 1) == 0)
			_printf("%s=\'%s\'\n", ptr->str, ptr->val);
		ptr = ptr->next;
	}
	params->status = 0;
}

/**
 * print_all_aliases - this is the funct to print all aliases in the alias list
 * @params: this is the param struct containing the alias list
*/
void print_all_aliases(param_t *params)
{
	print_list_alias(params->alias_head);
	params->status = 0;
}

/**
 * print_list_alias - print name and val of each alias in a linked list
 * @head: the pointer points to the head of the linked list
 *
 * It iterates through the linked list of aliases and print the name
 
*/
void print_list_alias(list_t *head)
{
	if (head)
	{
		print_list_alias(head->next);
		if (head->str != NULL)
			_printf("%s=\'%s\'\n", head->str, head->val);
	}
}
