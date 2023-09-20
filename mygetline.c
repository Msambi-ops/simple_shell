#include <unistd.h>
#include <stdlib.h>
#include "shell.h"
#include "main.h"
#define BUFFER_SIZE 4096
#define READ_SIZE 1024

/**
 * rlLine - Resize the line bufferResize the line buffer
 * @line: to be stored temporarily
 * @oldSize: acquired temporarily
 * @newSize: something blue
 *
 * Return: fresly allocated buffer
 */
char *rlLine(char **line, unsigned int oldSize, unsigned int newSize)
{
	char *newLine = NULL;
	unsigned int n;

	newLine = malloc(newSize);
	if (newLine)
	{
		for (n = 0; n < oldSize; n++)
			newLine[n] = (*line)[n];
		free(*line);
		*line = newLine;
	}
	return (newLine);
}
/**
 * _getline - Reads a line of characters
 * from standard input (stdin)
 * @params: parameters
 *
 * Return: The count of characters that were read
 */
int _getline(param_t *params)
{
	char *line = NULL;
	static unsigned int buffeSize = BUFFER_SIZE;
	char *writeHead = line;
	unsigned int length;

	line = malloc(BUFFER_SIZE);
	do {
		length = read(0, writeHead, BUFFER_SIZE);
		if (length == 0)
			break;
		writeHead += length;
		if (writeHead >= (line + BUFFER_SIZE - 1 - READ_SIZE))
		{
			line = rlLine(&line, buffeSize, buffeSize * 2);
			buffeSize *= 2;
		}
	} while (*(writeHead - 1) != '\n');

	free(params->buffer);
	params->buffer = line;
	if (length == 0)
		return (-1);
	return (_strlen(params->buffer));
}
