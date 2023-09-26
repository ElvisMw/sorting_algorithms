#include "sort.h"

void swap_ints(int *e_m, int *b_k)
{
	int tmp;
	tmp = *e_m;
	*e_m = *b_k;
	*b_k = tmp;
}

void shell_sort(int *array, size_t size)
{
	size_t gap, l, s;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (l = gap; l < size; l++)
		{
			s = l;
			while (s >= gap && array[s - gap] > array[s])
			{
				swap_ints(array + s, array + (s - gap));
				s -= gap;
			}
		}
		print_array(array, size);
	}
}
