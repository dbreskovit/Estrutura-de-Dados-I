#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h"

void vtrMaximum(int *vtr, int sz, int *max, int *count)
{
    if (!sz)
        return;

    if (*vtr > *max)
    {
        *max = *vtr;
        *count = 1;
    }
    else if (*vtr == *max)
        (*count)++;

    vtrMaximum(vtr + 1, sz - 1, max, count);
}

int main(void)
{
    srand(time(NULL));

    int vector[10];
    int size = len(vector);

    for (int i = 0; i < size; i++)
        vector[i] = rand() % 7;

    printf("original vector: ");
    vtrPrintf(vector, size);

    int max = vector[0];
    int count = 0;

    vtrMaximum(vector, size, &max, &count);

    printf("\nmax value: %d\n", max);
    printf("count: %d\n", count);

    return 1;
}