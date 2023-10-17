
#include "main.h"

/**
  * _settingmem - This is responsible for setting memory
  * @k:- Num of the bytes
  * @c:- const bytes
  * @j:- the print location
  * Return:- True as 0
  */

char *_settingmem(char *j, char c, unsigned int k)
{
	unsigned int x = 0;

	while (x < k)
	{
		j[x] = c;
		x++;
	}


	return (j);
}

/**
  * own_realloc - Allocates the memory
  * @sizenw:- The memory size
  * @pointer:- The previuos allocation
  * Return:- True as 0
  */

char *own_realloc(char *pointer, size_t sizenw)
{
	size_t j = 0;
	size_t sizeod = own_strlen(pointer);
	char *repointed;

	if (sizenw == sizeod)
		return (pointer);

	if (sizenw == 0 && pointer != NULL)
	{
		free(pointer);
		return (NULL);
	}

	repointed = malloc(sizenw);
	if (!repointed)
	{
		return (pointer);
	}

	if (pointer)
	{
		for (j = 0; j < sizeod && j < sizenw; j++)
		{
			*(repointed + j) = *(pointer + j);
		}

	}
	_settingmem((repointed + sizeod), 0, (sizenw - sizeod));

	return (repointed);
}

/**
  * freeing_memlst - Frees the memory
  * @head:- Prints to the strct
  */

void freeing_memlst(mem_list **head)
{
	mem_list *pmt;

	if (head)
	{
		while (*head)
		{
			pmt = *head;
			*head = (*head)->next;

			if (pmt->mem_ptr)
			{
				free(pmt->mem_ptr);
			}
			free(pmt);
		}

		*head = NULL;
	}
}

/**
  * add_memnode - Joins the nodes
  * @pointer:- Points to the new node
  * @head:- Points to the previous node
  * Return:- True as 0
  */

mem_list *add_memnode(mem_list **head, char *pointer)
{
	mem_list *nw;

	nw = malloc(sizeof(mem_list));

	if (!nw)
		return (NULL);

	nw->mem_ptr = pointer;
	nw->next = *head;

	*head = nw;

	return (*head);
}

/**
  * alloc_mngr - Allocating space for memory
  * @pointer:- Pointing to the new memory
  * @siz:- the size limit
  * Return:-  0
  */



char *alloc_mngr(char *pointer, size_t siz)
{
	pointer = own_realloc(pointer, siz);

	if (!(pointer))
	{
		perror("hsh");
		freeing_memlst(&mem_head);
		return (NULL);
	}

	mem_head = add_memnode(&mem_head, pointer);

	return (pointer);
}
