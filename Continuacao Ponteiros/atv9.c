#include <stdio.h>
#include "lib.h"

void mtxSum(int A[][3], int B[][3], int C[][3])
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            C[i][j] = A[i][j] + B[i][j];
}

int main(void)
{

    int A[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int B[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int C[3][3];

    mtxSum(A, B, C);

    printf("A:\n");
    mtxPrint(&A, (sizeof(A) / sizeof(A[0])));

    printf("B:\n");
    mtxPrint(&B, (sizeof(B) / sizeof(B[0])));

    printf("C:\n");
    mtxPrint(&C, (sizeof(C) / sizeof(C[0])));

    return 1;
}