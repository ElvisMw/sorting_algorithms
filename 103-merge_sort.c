#include "sort.h"

void merge_subarr(int *e_m, int *buff, size_t front, size_t mid,
                  size_t back);
void merge_sort_recursive(int *e_m, int *buff, size_t front, size_t back);
void merge_sort(int *e_m, size_t size);

void merge_subarr(int *e_m, int *buff, size_t front, size_t mid, size_t back)
{
    size_t l, s, k = 0;

    printf("Merging...\n[left]: ");
    print_array(e_m + front, mid - front);

    printf("[right]: ");
    print_array(e_m + mid, back - mid);

    for (l = front, s = mid; l < mid && s < back; k++)
        buff[k] = (e_m[l] < e_m[s]) ? e_m[l++] : e_m[s++];
    for (; l < mid; l++)
        buff[k++] = e_m[l];
    for (; s < back; s++)
        buff[k++] = e_m[s];
    for (l = front, k = 0; l < back; l++)
        e_m[l] = buff[k++];

    printf("[Done]: ");
    print_array(e_m + front, back - front);
}

void merge_sort_recursive(int *e_m, int *buff, size_t front, size_t back)
{
    size_t mid;

    if (back - front > 1)
    {
        mid = front + (back - front) / 2;
        merge_sort_recursive(e_m, buff, front, mid);
        merge_sort_recursive(e_m, buff, mid, back);
        merge_subarr(e_m, buff, front, mid, back);
    }
}

void merge_sort(int *e_m, size_t size)
{
    int *buff;

    if (e_m == NULL || size < 2)
        return;

    buff = malloc(sizeof(int) * size);
    if (buff == NULL)
        return;

    merge_sort_recursive(e_m, buff, 0, size);

    free(buff);
}
