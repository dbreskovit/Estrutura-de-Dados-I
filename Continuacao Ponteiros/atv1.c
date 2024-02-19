#include <stdio.h>
#include "lib.h"

void initialize(float *vtr, int sz)
{
    if (!sz)
        return;

    *vtr = 4.2;
    initialize(vtr + 1, sz - 1);
}

void printVA(float *vtr, int sz)
{
    if (!sz)
        return;

    printf("Value: %.2f | Address: %p\n", *vtr, vtr);
    return printVA(vtr + 1, sz - 1);
}

int main(void)
{
    float vector[10];
    int size = len(vector);

    initialize(vector, size);
    printVA(vector, size);

    return 1;
}