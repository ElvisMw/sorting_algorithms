#include "sort.h"

int get_max(int *e_m, int size);
void radix_counting_sort(int *e_m, size_t size, int sig, int *buff);
void radix_sort(int *e_m, size_t size);

int get_max(int *e_m, int size)
{
    int max, l;

    for (max = e_m[0], l = 1; l < size; l++)
    {
        if (e_m[l] > max)
            max = e_m[l];
    }

    return (max);
}

void radix_counting_sort(int *e_m, size_t size, int sig, int *buff)
{
    int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    size_t l;

    for (l = 0; l < size; l++)
        count[(e_m[l] / sig) % 10] += 1;

    for (l = 0; l < 10; l++)
        count[l] += count[l - 1];

    for (l = size - 1; (int)l >= 0; l--)
    {
        buff[count[(e_m[l] / sig) % 10] - 1] = e_m[l];
        count[(e_m[l] / sig) % 10] -= 1;
    }

    for (l = 0; l < size; l++)
        e_m[l] = buff[l];
}

void radix_sort(int *e_m, size_t size)
{
    int max, sig, *buff;

    if (e_m == NULL || size < 2)
        return;

    buff = malloc(sizeof(int) * size);
    if (buff == NULL)
        return;

    max = get_max(e_m, size);
    for (sig = 1; max / sig > 0; sig *= 10)
    {
        radix_counting_sort(e_m, size, sig, buff);
        print_array(e_m, size);
    }

    free(buff);
}
