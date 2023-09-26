#include "sort.h"

void swap_ints(int *e_m, int *b_k);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

void swap_ints(int *e_m, int *b_k)
{
    int tmp;

    tmp = *e_m;
    *e_m = *b_k;
    *b_k = tmp;
}

void max_heapify(int *array, size_t size, size_t base, size_t root)
{
    size_t left, right, large;

    left = 2 * root + 1;
    right = 2 * root + 2;
    large = root;

    if (left < base && array[left] > array[large])
        large = left;
    if (right < base && array[right] > array[large])
        large = right;

    if (large != root)
    {
        swap_ints(array + root, array + large);
        max_heapify(array, size, base, large);
    }
}

void heap_sort(int *array, size_t size)
{
    int l;

    if (array == NULL || size < 2)
        return;

    for (l = (size / 2) - 1; l >= 0; l--)
        max_heapify(array, size, size, l);

    for (l = size - 1; l > 0; l--)
    {
        swap_ints(array, array + l);
        max_heapify(array, size, l, 0);
    }
}
