#include <stdio.h>
#include "sort.h"

void print_list(const listint_t *list)
{
	int l;

	l = 0;
	while (list)
	{
		if (l > 0)
			printf(", ");
		printf("%d", list->n);
		++l;
		list = list->next;
	}
	printf("\n");
}
