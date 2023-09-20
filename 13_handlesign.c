#include <unistd.h>
/**
 * sigint_handler - this function handles terminate signal.,
 * @s: signal no.
 */
void sigint_handler(int __attribute__((unused)) s)
{
	write(1, "\n($) ", 5);
}

