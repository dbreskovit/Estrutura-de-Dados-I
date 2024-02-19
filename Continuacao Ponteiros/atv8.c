#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h"

void vtrInvert(int *vtr, int sz)
{
    if (!sz)
        return;

    int aux = vtr[0];
    vtr[0] = vtr[sz - 1];
    vtr[sz - 1] = aux;

    vtrInvert(vtr + 1, sz - 2);

    return;
}

int main()
{
    srand(time(NULL));

    int vtr[20];

    for (int i = 0; i < 20; i++)
        vtr[i] = rand() % 100;

    printf("Original:\n");
    vtrPrintf(vtr, 20);
    printf("\n");

    vtrInvert(vtr, 20);

    printf("Reverse:\n");
    vtrPrintf(vtr, 20);

    return 1;
}