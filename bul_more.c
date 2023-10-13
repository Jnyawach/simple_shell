#include "main.h"

/**
  * counting_digt -Counts the digits
  * @number:- Counted number
  * Return:- 0 Always
  */

size_t counting_digt(size_t number)
{
	size_t digitctn = 0;

	while (number != 0)
	{
		number /= 10;
		digitctn++;
	}

	return (digitctn);
}

/**
  * own_itoa - Changes num to string
  * @ba:- String base
  * @buff:- String array
  * @num:- Input
  * Return:- O Always
  */

char *own_itoa(size_t num, char *buff, int ba)
{
	int sign = 1;
	int idy = 0;
	size_t remember = 0;

	if (num == 0)
	{
		buff[idy++] = '0';
		buff[idy] = '\0';
	}
	while (num)
	{
		remember = num % ba;
		buff[idy++] = '0' + remember;
		num /= ba;
	}
	if (sign < 0)
	{
		buff[idy++] = '-';
	}
	if (num)
		buff[idy] = '\0';
	return (reverse_string(buff));
}
