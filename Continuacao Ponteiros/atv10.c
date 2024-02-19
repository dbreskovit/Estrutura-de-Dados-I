#include <stdio.h>
#include "lib.h"

void intIncrease(int *var)
{
    (*var)++;
}

void vtrIncrease(int *vtr, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        vtr[i]++;
    }
}

void mtxIncrease(int mtx[2][2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            mtx[i][j]++;
        }
    }
}

int main(void)
{
    int var = 0;
    int vtr[2] = {0, 0};
    int mtx[2][2] = {{0, 0}, {0, 0}};

    intIncrease(&var);
    vtrIncrease(vtr, 2);
    mtxIncrease(mtx);

    printf("var: %d\n", var);

    printf("vtr: \n");
    vtrPrintf(vtr, 2);

    printf("mtx: \n");
    mtxPrint(mtx, 2);

    return 1;
}