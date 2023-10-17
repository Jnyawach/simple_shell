#include "main.h"

/**
  * reverse_string - Reverses string
  * @input_str:- string
  * Return:- Always 0
  */

char *reverse_string(char *input_str)
{
	char temp_char;
	int index1 = 0, index2 = 0, len = 0, full = 0;
	char *reversed_str = input_str;

	len = own_strlen(input_str);

	if (len % 2 == 0)
	{
		full = len / 2;
	}
	else
	{
		full = (len - 1) / 2;
	}

	for (index1 = len - 1; index1 >= full; index2++, index1--)
	{
		temp_char = reversed_str[index2];
		reversed_str[index2] = input_str[index1];
		input_str[index1] = temp_char;
	}

	return (input_str);

}

/**
  * freeing_static_memorylst - Frees pointr
  * @head:- pointer
  */

void freeing_static_memlst(mem_list **head)
{
	mem_list *mpt;

	if (head)
	{
		while (*head)
		{
			mpt = *head;
			*head = (*head)->next;
			if (mpt->mem_ptr)
			{
				free(mpt->mem_ptr);
			}
			free(mpt);
		}


		*head = NULL;
	}
}


