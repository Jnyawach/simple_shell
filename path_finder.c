
#include "main.h"

/**
  * getting_pathh - Get paths
  * @argv:- CMD args
  * Return:- Always 0
  */

char **getting_pathh(char *const *argv)
{
	char *path_pointer = NULL;
	char *reff = "PATH=";
	char **pat = NULL;
	size_t path_counter, env_i = 0, p_j;
	size_t pat_ctsiz;

	while (environ[env_i])
	{
		if (own_strncmp(reff, environ[env_i], 5) == 0)
		{
			path_pointer = &environ[env_i][5];
			path_counter = counting_path(path_pointer);
			pat = (char **)alloc_mngr((char *)pat,
				(sizeof(char *) * (path_counter + 1)));

			for (p_j = 0; p_j < path_counter; p_j++)
			{
				pat_ctsiz = (length_path(path_pointer) + own_strlen(argv[0]) + 2);
				pat[p_j] = alloc_mngr(pat[p_j], (sizeof(char) * pat_ctsiz));

				own_strncpy(pat[p_j], path_pointer, length_path(path_pointer));
				own_strcat(pat[p_j], "/");
				own_strcat(pat[p_j], argv[0]);

				path_pointer = (path_pointer + (length_path(path_pointer) + 1));
			}
			pat[p_j] = NULL;
			return (pat);
		}
		env_i++;
	}

	return (NULL);
}

/**
  * checking_path - function that checks path
  * @argv:- commandline args
  * Return:- Always 0
  */


size_t checking_path(char *const *argv)
{
	size_t j = 0;
	size_t path_i = 0;

	while (argv[0][j])
	{
		if (argv[0][j] == '/')
		{
			path_i = 1;
			break;
		}
		j++;
	}
	return (path_i);
}

/**
  * counting_path - function that return path cnt
  * @pat:- environ Path
  * Return:- Always 0
  */

size_t counting_path(char *pat)
{
	size_t j;
	size_t count_pat = 0;

	if (!pat)
	{
		return (0);
	}

	for (j = 0; pat[j]; j++)
	{
		if ((pat[j + 1] == ':' || pat[j + 1] == '\0'))
		{
			count_pat++;
		}
	}

	return (count_pat);
}

/**
  * length_path - function that is taks path
  * @pat_pointer:- ptr to path current
  * Return:- Always 0
  */

size_t length_path(char *pat_pointer)
{
	size_t j = 0;

	if (pat_pointer)
	{
		while (pat_pointer[j] != ':' && pat_pointer[j] != '\0')
		{
			j++;
		}
	}

	return (j);
}

