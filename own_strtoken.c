
#include "main.h"

size_t cnt_tokens(char *buffer);
size_t tok_length(char *buf, size_t tokneed);

/**
  * own_strtok - Tokenizess string
  * @buffer:- Str tokenized
  * Return:- Success 0
  */

char **own_strtok(char *buffer)
{
	size_t tokenamount;
	size_t allocsize;
	size_t toklen = 0, tokcurr = 1;
	size_t lineit = 0, tokit = 0, i = 0;
	char **tok_array = NULL;

	tokenamount = cnt_tokens(buffer);
	if (tokenamount == 0)
		return (NULL);

	allocsize = (tokenamount + 1) * (sizeof(char *));
	tok_array = (char **)alloc_mngr((char *)tok_array, allocsize);
	if (tok_array == NULL)
		return (NULL);

	for (i = 0; tokcurr <= tokenamount; tokcurr++, i++)
	{
		toklen = tok_length(buffer, tokcurr);

		allocsize = (toklen + 1) * (sizeof(char));
		tok_array[i] = alloc_mngr(tok_array[i], allocsize);
		if (tok_array[i] == NULL)
			return (NULL);

		while (buffer[lineit] == ' ' || buffer[lineit] == '\t')
			lineit++;

		for (tokit = 0; tokit < toklen; tokit++, lineit++)
			tok_array[i][tokit] = buffer[lineit];

		tok_array[i][tokit] = '\0';
	}

	tok_array[i] = NULL;

	return (tok_array);
}

/**
 * cnt_tokens - Counts amount of tokens
 * @buf: Str to be counted
 *
 * Return: Total amount of tokens
 */
size_t cnt_tokens(char *buf)
{
	size_t it = 0, tokenamount = 0;

	while (buf[it] != '\0')
	{
		if ((buf[it + 1] == ' ' || buf[it + 1] == '\t') || buf[it + 1] == '\0')
			if (buf[it] != ' ' && buf[it] != '\t')
				tokenamount++;
		it++;
	}
	return (tokenamount);
}

/**
 * tok_length - Length of specified token
 * @buf: Token contained string
 * @tokneed: Specifies needed token
 *
 * Return: Length of the specified token
 */
size_t tok_length(char *buf, size_t tokneed)
{
	size_t it = 0, toklen = 0, tokcurr = 0;

	while (tokcurr < tokneed)
	{
		while (buf[it] == ' ' || buf[it] == '\t')
			it++;

		if (buf[it] != '\0' && buf[it] != ' ' && buf[it] != '\t')
		{
			tokcurr++;
			while (buf[it] != '\0' && buf[it] != ' ' && buf[it] != '\t')
			{
				if (tokcurr == tokneed)
					toklen++;
				it++;
			}
		}
	}
	return (toklen);
}

