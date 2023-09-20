#ifndef LISTSH
#define LISTSH

#include <unistd.h>

/**
 * struct list_s - Node in a singly linked list
 * @str: is the string data
 * @val: string data value
 * @len: length of the string data
 * @valLen: Size of the value text
 * @next: pointer to the next node in the list
 *
 * Description: This structure defines a unit within a singly linked list
 * utilized in the ALX shell project
*/

typedef struct list_s
{
	char *str;
	char *val;
	unsigned int len;
	unsigned int valLen;
	struct list_s *next;
} list_t;

int _putchar(char c);

size_t print_list(list_t *h);

size_t list_len(list_t *h);

list_t *add_node(list_t **head, char *str, char *val);

void free_list(list_t *head);

list_t *get_node(list_t *head, char *str);


#endif
