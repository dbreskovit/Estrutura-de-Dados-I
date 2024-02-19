#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *vector = NULL;
    int size = 0;
    int i = 0;
    int value = 0;

    printf("Enter the size of vector: ");
    scanf("%d", &size);

    vector = (int *)malloc(size * sizeof(int));

    if (vector == NULL)
    {
        printf("Memory allocation error!\n");
        exit(1);
    }

    printf("Enter the values of vector: ");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &value);

        if (value < 0)
            break;

        vector[i] = value;
    }

    vector = (int *)realloc(vector, i * sizeof(int));

    size = i;

    printf("Vector: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", vector[i]);
    }
    printf("\n");

    free(vector);
    vector = NULL;

    return 1;
}