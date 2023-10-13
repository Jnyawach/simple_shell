#include "main.h"

int is_num(char let);
int own_atoi(char *status);

/**
 * bltin_exit - Exits shell CLI
 * @argv: Exits with Shell status
 *
 * Return: Exits shell or returns EXIT_FAILURE
 */
int bltin_exit(char *const *argv)
{
	int awl;

	if (argv[1] == NULL)
	{
		freeing_memlst(&mem_head);
		freeing_static_memlst(&static_mem_head);
		exit(EXIT_SUCCESS);
	}
	else
	{
		awl = own_atoi(argv[1]);

		switch (awl)
		{
			case (-1):
				return (EXIT_FAILURE);
			default:
				freeing_memlst(&mem_head);
				freeing_static_memlst(&static_mem_head);
				exit(awl);
		}
	}
}

/**
 * is_num - Checks of Char is Num
 * @let: Inputed char
 * Return: Success 1 : Failure 0
 */
int is_num(char let)
{
	if (let >= '0' && let <= '9')
		return (1);

	return (0);
}

/**
 * own_atoi - Convert string to number
 * @status: Input string
 * Return: Status as an int or -1
 */
int own_atoi(char *status)
{
	int awl = 0;
	int i = 0;

	if (status[i] == '-')
		return (-1);

	for (i = 0; status[i] != '\0'; i++)
	{
		if (is_num(status[i]))
		{
			awl = awl * 10 + status[i] - '0';
		}
		else
			return (-1);
	}
	if (awl > 2147483647)
	{
		return (-1);
	}
	else
		return (awl);
}

