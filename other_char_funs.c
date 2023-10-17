
#include "main.h"

/**
  * rev_arry - Reverses array
  * @ar:- reverseed array
  * @length:- Array size
  * Return:- Success 0
  */


void rev_arry(char *ar, int length)
{
	int j = 0;
	char tmp;

	for (; j < (length / 2); j++)
	{
		tmp = ar[j];
		ar[j] = ar[(length - 1) - j];
		ar[(length - 1) - j] = tmp;
	}
}

/**
  * own_intlen - Return length of num
  * @number:- The checked number
  * Return:- Success 0
  */

int own_intlen(int number)
{
	int size = 0;

	while (number != 0)
	{
		size++;
		number /= 10;

	}

	return (size);
}


/**
  * own_isalpha - check if char is_alpha
  * @f:- The provided char
  * Return:- Success 0
  */

int own_isalpha(int f)
{
	if (((f >= 97) && (f <= 122)) || ((f >= 65) && (f <= 90)))
		return (1);

	else
		return (0);
}
