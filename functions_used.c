#include <unistd.h>
#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _tokenizer - tokenizes a string and returns it as a double pointer
 * @string: string to be tokenized
 * @delim: delimitor to be used to tokenize
 * Return: double pointer if succesful
 */

char **_tokenizer(char *string, char *delim)
{
	char **tokens;
	char *store;
	int i = 0;

	store = malloc(sizeof(char) * strlen(string) + 1);
	if (store == NULL)
	{
		return (NULL);
	}
	store = _strcpy(store, string);
	tokens = malloc(sizeof(tokens));
	if (tokens == NULL)
	{
		return (NULL);
	}
	tokens[i] = strtok(store, delim);
	while (tokens[i] != NULL)
	{
		i++;
		tokens = realloc(tokens, (i + 1) * sizeof(tokens));
		if (tokens == NULL)
		{
			_free_double(tokens);
			return (NULL);
		}
		tokens[i] = strtok(NULL, delim);
	}
	return (tokens);
}

/**
 * _getpath - goes to environment and extracts the path
 * @envp: contains environment
 * @name: name of the variable to extract (path)
 * Return: path if succesful, NULL if failure
 */

char *_getpath(char *envp[], char *name)
{
	char **buffer, *path;
	int i;

	for (i = 0; envp[i] != NULL; i++)
	{
		buffer = _tokenizer(envp[i], "=");
		if (_strcmp(buffer[0], name) == 0)
		{
			path = malloc(sizeof(char) * _strlen(buffer[1]) + 1);
			_strcpy(path, buffer[1]);
			_free_double(buffer);
			return (path);
		}
		_free_double(buffer);
	}
	return (NULL);
}

/**
 * _dirmatch - matches command with correct directory in path
 * @path: string containing the path
 * @input: command to match with path
 * Return: matched command if found, input if no match
 */

char *_dirmatch(char *path, char *input)
{
	char **dir;
	char *command, *temp, storage[300], slash[77] = "/";
	int i;
	struct stat info;

	dir = _tokenizer(path, ":");

	temp = _strcat(slash, input);

	for (i = 0; dir[i] != NULL; i++)
	{
		_strcpy(storage, dir[i]);
		command = _strcat(storage, temp);
		if (stat(command, &info) == 0)
		{
			_free_double(dir);
			return (command);
		}
	}
	_free_double(dir);
	return (input);
}

/**
 * _exec - executes valid command
 * @string: string containing valid command
 * @command: double pointer containing command arguments
 * @envp: environment
 * Return: 0 if succesful
 */

int _exec(char *string, char **command, char **envp)
{
	pid_t pid;
	int status;
	struct stat info;

	if (stat(string, &info) == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			if (execve(string, command, envp))
			{
				_free_double(command);
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}
		if (pid > 0)
		{
			_free_double(command);
			wait(&status);
		}
	}
	else
	{
		return (-1);
	}
	return (0);
}


