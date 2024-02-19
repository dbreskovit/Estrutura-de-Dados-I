#include <stdlib.h>
#include <stdio.h>

void readSize(int *sz);
void allocate(int **vtr, int *sz);
void readVector(int *vtr, int sz);
void printVector(int *vtr, int sz);

int main(void)
{
    int size, *vector;

    allocate(&vector, &size);
    readVector(vector, size);
    printVector(vector, size);

    free(vector);
    vector = NULL;

    return 1;
}

void readSize(int *sz)
{
    printf("Enter with the size of the vector: ");
    scanf("%d", sz);

    if (*sz <= 0)
    {
        printf("Invalid size!\n");
        exit(1);
    }
    printf("\n");
}

void allocate(int **vtr, int *sz)
{
    readSize(sz);

    *vtr = (int *)malloc(*sz * sizeof(int));

    if (*vtr == NULL)
    {
        printf("Memory allocation error!\n");
        exit(1);
    }
}

void readVector(int *vtr, int sz)
{
    for (int i = 0; i < sz; i++)
    {
        printf("Enter with the value [%d]: ", i + 1);
        scanf("%d", &vtr[i]);
    }
    printf("\n");
}

void printVector(int *vtr, int sz)
{
    while (sz--)
        printf("%d ", *vtr++);
}