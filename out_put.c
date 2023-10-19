#include "main.h"

/**
 * bltin_env - Print procee env
 * @argv: The command table
 *
 * Return: 0 Success, -1 Failure
 */
int bltin_env(char *const *argv)
{
	size_t length, row;

	if (!argv[1])
	{
		for (row = 0; environ[row]; row++)
		{
			length = own_strlen(environ[row]);

			if ((write(STDOUT_FILENO, environ[row], length)) == -1)
				return (-1);
			if ((write(STDOUT_FILENO, "\n", 1)) == -1)
				return (-1);
		}
	}
	else
	{
		errno = ENOENT;
		return (-1);
	}
	return (0);
}

