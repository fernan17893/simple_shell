#include "main.h"

/**
 * _printenv - prints environment
 * @envp: environment
 * Return: 0 if succesful
 */

int _printenv(char *envp[])
{
	int i, n;

	for (i = 0; envp[i] != NULL; i++)
	{
		n = _strlen(envp[i]);
		write(1, envp[i], n);
		_putchar('\n');
	}
	return (0);
}

/**
 * _free_double - frees a double pointer and sets it to NULL
 * @token: double pointer to free
 * Return: 0 if succesful
 */

int _free_double(char **token)
{
	int i = 0;

	if (token != NULL)
	{
		while (token[i] != NULL)
		{
			i++;
		}
		free(token[i + 1]);
		token[i + 1] = NULL;
		free(token);
		token = NULL;
	}
	return (0);
}

#include "main.h"

/**
 * _check_program - checks if program is valid before passing to execve
 * @program: program to validate
 * Return: 0 if valid, -1 otherwise
 */

int _check_program(char *program)
{
	struct stat status;

	if (stat(program, &status) == 0)
	{
		return (0);
	}
	else
	{
		return (-1);
	}
}

/**
 * _verifier - verifies if string is whitespace, new line or tab
 * @string: string to be verifed
 * @envp: environment
 * Return: 1 if non match, 0 if always match
 */

int _verifier(char *string, char **envp)
{
	int i;

	if (_strcmp(string, "env\n") == 0)
	{
		_printenv(envp);
		return (0);
	}
	else
	{
		for (i = 0; i < _strlen(string); i++)
		{
			if (string[i] == ' ' || string[i] == '\n' || string[i] == '\t')
				;
			else
			{
				return (1);
			}
		}
	}
	return (0);
}
