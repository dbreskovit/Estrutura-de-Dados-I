#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **createMatrix(int i, int j);
void fillMatrix(int **matrix, int i, int j);
int searchValue(int **matrix, int i, int j, int value);
void printMatrix(int **matrix, int i, int j);
void freeMatrix(int **matrix, int i);

int main(void)
{
    int **matrix = NULL;
    int i = 0;
    int j = 0;
    int value = 0;
    int result = 0;

    printf("Enter the number of rows: ");
    scanf("%d", &i);

    printf("Enter the number of columns: ");
    scanf("%d", &j);

    matrix = createMatrix(i, j);

    fillMatrix(matrix, i, j);

    printf("Enter the value to search: ");
    scanf("%d", &value);

    result = searchValue(matrix, i, j, value);

    if (result == 1)
        printf("Value found!\n");
    else
        printf("Value not found!\n");

    printMatrix(matrix, i, j);

    freeMatrix(matrix, i);

    return 1;
}

int **createMatrix(int i, int j)
{
    int **matrix = NULL;
    int k = 0;

    matrix = (int **)malloc(i * sizeof(int *));

    if (matrix == NULL)
    {
        printf("Memory allocation error!\n");
        exit(1);
    }

    for (k = 0; k < i; k++)
    {
        matrix[k] = (int *)malloc(j * sizeof(int));

        if (matrix[k] == NULL)
        {
            printf("Memory allocation error!\n");
            exit(1);
        }
    }

    return matrix;
}

void fillMatrix(int **matrix, int i, int j)
{
    int k = 0;
    int l = 0;

    srand(time(NULL));

    for (k = 0; k < i; k++)
    {
        for (l = 0; l < j; l++)
        {
            matrix[k][l] = rand() % 101;
        }
    }
}

int searchValue(int **matrix, int i, int j, int value)
{
    int k = 0;
    int l = 0;

    for (k = 0; k < i; k++)
    {
        for (l = 0; l < j; l++)
        {
            if (matrix[k][l] == value)
                return 1;
        }
    }

    return 0;
}

void printMatrix(int **matrix, int i, int j)
{
    int k = 0;
    int l = 0;

    printf("Matrix:\n");
    for (k = 0; k < i; k++)
    {
        for (l = 0; l < j; l++)
        {
            printf("%d ", matrix[k][l]);
        }
        printf("\n");
    }
}

void freeMatrix(int **matrix, int i)
{
    int k = 0;

    for (k = 0; k < i; k++)
    {
        free(matrix[k]);
        matrix[k] = NULL;
    }

    free(matrix);
    matrix = NULL;
}
