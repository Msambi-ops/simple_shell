#include <unistd.h>
#include "shell.h"
#include "main.h"
/**
 * write_error - this funct writes error message to stderr.,
 * @params: params struct containing info about the command and program
 * @msg: error msg to print
 *
 * This funct takes a param struct containing info about current
 * command and program and an error msg to print to stderr.
*/
void write_error(param_t *params, char *msg)
{
	char errBuffer[1024] = {0};
	char *writeHead = errBuffer, *bufPtr = errBuffer;

	_strcpy(writeHead, params->argv[0]);
	writeHead = bufPtr + _strlen(bufPtr);
	_strcpy(writeHead, ": ");
	writeHead = bufPtr + _strlen(bufPtr);
	_strcpy(writeHead, get_number(params->lineCount));
	writeHead = bufPtr + _strlen(bufPtr);
	_strcpy(writeHead, ": ");
	writeHead = bufPtr + _strlen(bufPtr);
	_strcpy(writeHead, params->args[0]);
	writeHead = bufPtr + _strlen(bufPtr);
	_strcpy(writeHead, ": ");
	writeHead = bufPtr + _strlen(bufPtr);
	_strcpy(writeHead, msg);
	writeHead = bufPtr + _strlen(bufPtr);

	write(STDERR_FILENO, errBuffer, _strlen(bufPtr));
}
