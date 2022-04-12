#include "main.h"

/**
* _strcat - appends one string to the end of another
* @dest: string being modified
* @src: string being appended to modified string
*
* Return: modified string
*/

char *_strcat(char *dest, char *src)
{
	int count = 0;
	int length = 0;

	while (dest[length] != '\0')
	{
		length++;
	}

	/*length--;*/

	for (count = 0; count < length && src[count] != '\0'; count++)
	{
		dest[length] = src[count];
		length++;
	}
	dest[length] = '\0';

	return (dest);
}

/**
 * _strlen - counts the amount of characters in a string
 * @s: pointer, points to the value of a variable
 *
 * Return: returns the amount of characters in string
 */

int _strlen(char *s)
{
	int charCount = 0;

	while (s[charCount] != '\0')
	{
		charCount++;
	}

	return (charCount);
}

/**
* _strcmp - compares two strings and determines which string is greater
* @s1: string 1
* @s2: string 2
*
* Return: 0 if equal, string one minus string two if non equal
*/

int _strcmp(char *s1, char *s2)
{
	while ((*s1 != '\0' && *s2 != '\0') && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (s1 == s2)
	{
		return (0);
	}
	else
	{
		return (*s1 - *s2);
	}
}

/**
 * _strcpy - copies a string
 * @dest: pointer, points to where string is being copied
 * @src: pointer, points to string
 *
 *Return: value of dest
 */

char *_strcpy(char *dest, char *src)
{
	int count;
	int length = 0;

	while (src[length] != '\0')
	{
		length++;
	}

	/*length--;*/

	for (count = 0; count < length && src[count] != '\0'; count++)
	{
		dest[count] = src[count];
	}
	dest[count] = '\0';

	return (dest);
}

