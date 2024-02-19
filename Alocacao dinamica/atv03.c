#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *vector1 = NULL;
    int *vector2 = NULL;
    int size = 1000;
    int i = 0;
    int count1 = 0;
    int count2 = 0;

    vector1 = (int *)malloc(size * sizeof(int));
    vector2 = (int *)calloc(size, sizeof(int));

    if (vector1 == NULL || vector2 == NULL)
    {
        printf("Memory allocation error!\n");
        exit(1);
    }

    for (i = 0; i < size; i++)
    {
        if (vector1[i] == 0)
        {
            count1++;
        }
        if (vector2[i] == 0)
        {
            count2++;
        }
    }

    printf("Number of zeros in vector1: %d\n", count1);
    printf("Number of zeros in vector2: %d\n", count2);

    return 1;
}