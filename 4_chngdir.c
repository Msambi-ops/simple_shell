#include <unistd.h>
#include <stdlib.h>
#include "shell.h"
#include "main.h"
/**
 * _cd - the funct to change current working dir.,
 * @params: these are the shell parameters
 *
 * Return: the function returns void
 */
void _cd(param_t *params)
{
	char *target = NULL, cwd[1024];
	char **temp_args = NULL, **original_args = NULL;
	int i;

	if (params->tokCount == 1)
	{
		target = _getenv("HOME", params);
		if (!target)
		{
			params->status = 0;
			return;
		}
	}
	else if (params->args[1][0] == '-')
	{
		if (!_strcmp(params->args[1], "-"))
		{
			target = _getenv("OLDPWD", params);
			if (!target)
			{
				params->status = 0;
				target = _getenv("PWD", params);
				_printf("%s\n", target);
				free(target);
				return;
			}
			_printf("%s\n", target);
		}
		else
		{
			params->status = 2;
			_printf("%s: %d: cd: invalid choice %c%c\n",
				params->argv[0], params->lineCount,
				'-', params->args[1][1]);
			return;
		}
	}
	else
	{
		target = _strdup(params->args[1]);
		if (!target)
		{
			write(STDERR_FILENO, "cd into  target malloc error\n", 18);
			exit(-1);
		}
	}
	i = chdir(target);
	if (i)
	{
		write_error(params, "cannot cd to ");
		write(STDERR_FILENO, target, _strlen(target));
		write(STDERR_FILENO, "\n", 1);
		params->status = 0;
		free(target);
		return;
	}
	free(target);
	temp_args = malloc(sizeof(char *) * 3);
	if (!temp_args)
		exit(-1);
	original_args = params->args;
	params->args = temp_args;
	params->tokCount = 3;
	/* set OLDPWD to the current PWD */
	temp_args[0] = _strdup("setenv");
	temp_args[1] = _strdup("OLDPWD");
	if (!temp_args[0] || !temp_args[1])
	{
		write(STDERR_FILENO, "cd old PWD malloc error\n", 18);
		free_params(params);
		exit(-1);
	}
	temp_args[2] = _getenv("PWD", params);
	_setenv(params);
	for (i = 0; i < 3; i++)
		free(temp_args[i]);
	/* set PWD to the target wd */
	temp_args[0] = _strdup("setenv");
	temp_args[1] = _strdup("PWD");
	temp_args[2] = _strdup(getcwd(cwd, 1024));
	if (!temp_args[0] || !temp_args[1] || !temp_args[2])
	{
		write(STDERR_FILENO, "cd new PWD malloc error\n", 18);
		free_params(params);
		exit(-1);
	}
	_setenv(params);
	for (i = 0; i < 3; i++)
		free(temp_args[i]);
	free(temp_args);
	/* reset params */
	params->args = original_args;
}
