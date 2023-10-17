#include "main.h"

char *three_case(char *errcus, char **token_array);

/**
 * printing_error - Printed Error
 * @argv: Carry the shell name
 * @tok_arry: The needed token for error message
 * @loop_cnt: Shell loop iteration
 */
void printing_error(size_t loop_cnt, char *argv, char **tok_arry)
{
	char *tagged_err = NULL, *loop_num = NULL, *err_cus = NULL;
	size_t err_cus_len, tagged_err_len;
	size_t dig_amount = counting_digt(loop_cnt);
	size_t tok_len1 = own_strlen(tok_arry[0]), tok_len2 = own_strlen(tok_arry[1]);
	size_t argv_len = own_strlen(argv);
	size_t total_alloc = argv_len + dig_amount + tok_len1 + tok_len2 + 6;

	switch (err_msg)
	{
		case (2):
			err_cus = alloc_mngr(err_cus, (sizeof(char) * 12));
			err_cus = ": not found\0";
			break;
		case (3):
			err_cus = three_case(err_cus, tok_arry);
			if (err_cus == NULL)
				return;
			break;
		default:
			perror(argv);
			return;
	}

	loop_num = alloc_mngr(loop_num, (sizeof(char) * (dig_amount + 1)));
	own_itoa(loop_cnt, loop_num, 10);

	err_cus_len = own_strlen(err_cus);
	total_alloc += err_cus_len;

	tagged_err = alloc_mngr(tagged_err, sizeof(char) * total_alloc);

	own_strncpy(tagged_err, argv, argv_len);
	own_strcat(tagged_err, ": ");
	own_strcat(tagged_err, loop_num);
	own_strcat(tagged_err, ": ");
	own_strcat(tagged_err, tok_arry[0]);
	own_strcat(tagged_err, err_cus);
	if (err_msg == 3)
		own_strcat(tagged_err, tok_arry[1]);
	own_strcat(tagged_err, "\n");

	tagged_err_len = own_strlen(tagged_err);

	write(STDERR_FILENO, tagged_err, tagged_err_len);
}

/**
 * three_case - Create a custom error message
 * @errcus: Custom error message saved here
 * @token_array: The needed token for error message
 * Return: NULL or Pounter to error message
 */
char *three_case(char *errcus, char **token_array)
{
	size_t tok_len1 = own_strlen(token_array[0]);
	size_t tok_len2 = own_strlen(token_array[1]);

	if (tok_len1 == 4)
	{
		errcus = alloc_mngr(errcus, (sizeof(char) * 19));
		errcus = ": Illegal number: \0";
		return (errcus);
	}
	else if (tok_len1 == 2)
	{
		errcus = alloc_mngr(errcus, (sizeof(char) * 15));
		errcus = ": can't cd to \0";
		return (errcus);
	}

	errcus = alloc_mngr(errcus, sizeof(char) * tok_len1 + tok_len2 + 5);
	own_strncpy(errcus, token_array[0], tok_len1);
	own_strcat(errcus, ": '");
	own_strcat(errcus, token_array[1]);
	own_strcat(errcus, "'");

	errno = ENOENT;
	perror(errcus);
	return (NULL);
}

