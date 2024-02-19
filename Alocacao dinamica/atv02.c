#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void readMemory(int **memory, int *size);
void insertValue(int *memory, int size);
void readValue(int *memory, int size);
void printMemory(int *memory, int size);
void freeMemory(int *memory);

int main(void)
{
    int *mem = NULL;
    int sz = 0;
    int op = 0;

    readMemory(&mem, &sz);

    while (true)
    {
        printf("\n");
        printf("1 - Insert value\n");
        printf("2 - Read value\n");
        printf("3 - Print memory\n");
        printf("4 - Exit\n\n");

        printf("Enter the option: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            insertValue(mem, sz);
            break;
        case 2:
            readValue(mem, sz);
            break;
        case 3:
            printMemory(mem, sz);
            break;
        case 4:
            freeMemory(mem);
            exit(0);
            break;
        default:
            printf("Invalid option!\n");
            break;
        }
    }

    return 1;
}

void readMemory(int **memory, int *size)
{
    printf("Enter the size of memory: ");
    scanf("%d", size);

    if (*size <= 0)
    {
        printf("Invalid size!\n");
        exit(1);
    }

    *memory = (int *)calloc(*size, sizeof(int));

    if (*memory == NULL)
    {
        printf("Memory allocation error!\n");
        exit(1);
    }
}

void insertValue(int *memory, int size)
{
    int pos = 0;
    int val = 0;

    printf("Enter the position: ");
    scanf("%d", &pos);

    if (pos < 0 || pos >= size)
    {
        printf("Invalid position!\n");
        return;
    }

    printf("Enter the value: ");
    scanf("%d", &val);

    memory[pos] = val;
}

void readValue(int *memory, int size)
{
    int pos = 0;

    printf("Enter the position: ");
    scanf("%d", &pos);

    if (pos < 0 || pos >= size)
    {
        printf("Invalid position!\n");
        return;
    }

    printf("Value: %d\n", memory[pos]);
}

void printMemory(int *memory, int size)
{

    printf("Memory: ");

    printf("[ ");
    for (int i = 0; i < size; i++)
    {
        printf("%d", memory[i]);

        if (i < size - 1)
        {
            printf(", ");
        }
    }
    printf("]\n");
    printf("\n");
}

void freeMemory(int *memory)
{
    free(memory);
}
