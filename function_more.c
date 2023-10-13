
#include "main.h"

/**
  * own_strncpy - A function to copy Str
  * @destination:- Str destination
  * @source:- String
  * @count:- Copied Bytes
  * Return:- Success 0
  */

char *own_strncpy(char *destination, const char *source, size_t count)
{
	size_t h = 0;

	while (h < count)
	{
		if (source[h] == '\0')
		{
			break;
		}
		destination[h] = source[h];
		h++;
	}

	destination[h] = '\0';

	while (h < count)
	{
		destination[h] = '\0';
		h++;
	}

	return (destination);
}


/**
  * own_strlen - Get and return str length
  * @string:- String
  * Return:- Always 0
  */


size_t own_strlen(char *string)
{
	size_t string_len = 0;

	if (string)
		while (string[string_len] != '\0')
			string_len++;

	return (string_len);
}



/**
  * own_strcmp - Compare 2 strings
  * @string1:- str 1
  * @string2:- str 2
  * Return:- Always 0
  */

int own_strcmp(char *string1, char *string2)
{
	int h = 0;


	while (string1[h] != '\0')
	{
		if (string1[h] < string2[h])
		{
			return (string1[h] - string2[h]);
		}

		if (string1[h] > string2[h])
		{
			return (string1[h] - string2[h]);
		}
		h++;
	}

	if (string2[h] != '\0')
	{
		return (string1[h] - string2[h]);
	}

	return (0);
}


/**
  * own_strncmp - A function to compare two strings
  * @string1:- String one
  * @string2: String two.
  * @num:- Num of Chars to compare
  * Return:- Always 0
  */

int own_strncmp(char *string1, char *string2, size_t num)
{
	size_t m = 0;

	while (m < num && string1[m] != '\0')
	{
		if (string1[m] < string2[m])
		{
			return (string1[m] - string2[m]);
		}

		if (string1[m] > string2[m])
		{
			return (string1[m] - string2[m]);
		}

	m++;
	}
	if (m < num && string2[m] != '\0')
	{
		return (string1[m] - string2[m]);
	}
	return (0);
}



/**
  * own_strcat - joins strings
  * @destination:- joined string
  * @source: first string
  * Return:- Always 0
  */

char *own_strcat(char *destination, char *source)
{
	int src_ind = 0;
	int dest_ind = 0;


	for (; destination[dest_ind] != '\0';)
	{
		dest_ind++;
	}

	for (; source[src_ind] != '\0';)
	{
		destination[dest_ind] = source[src_ind];
		src_ind++;
		dest_ind++;
	}


	destination[dest_ind] = '\0';
	return (destination);
}

