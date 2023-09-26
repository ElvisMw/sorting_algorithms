#include <stdlib.h>
#include <stdio.h>

void print_array(const int *array, size_t size)
{
	size_t l;

	l = 0;
	while (array && l < size)
	{
		if (l > 0)
			printf(", ");
		printf("%d", array[l]);
		++l;
	}
	printf("\n");
}
