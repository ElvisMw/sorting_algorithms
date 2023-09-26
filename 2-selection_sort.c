#include "sort.h"

void swap_ints(int *e_m, int *b_k)
{
    int tmp;
    tmp = *e_m;
    *e_m = *b_k;
    *b_k = tmp;
}

void selection_sort(int *array, size_t size)
{
    int *min;
    size_t l, s;

    if (array == NULL || size < 2)
        return;

    for (l = 0; l < size - 1; l++)
    {
        min = array + l;
        for (s = l + 1; s < size; s++)
            min = (array[s] < *min) ? (array + s) : min;

        if ((array + l) != min)
        {
            swap_ints(array + l, min);
            print_array(array, size);
        }
    }
}
