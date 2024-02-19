#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h"

int vtrDouble(int *vtr, int sz)
{
    if (!sz)
        return 0;

    *vtr *= 2;
    return vtrDouble(vtr + 1, sz - 1);
}

int main(void)
{
    srand(time(NULL));

    int vector[5];
    int size = len(vector);

    for (int i = 0; i < size; i++)
        vector[i] = rand() % 100;

    printf("original vector: ");
    vtrPrintf(vector, size);

    vtrDouble(vector, size);

    printf("\ndouble vector: ");
    vtrPrintf(vector, size);

    return 1;
}