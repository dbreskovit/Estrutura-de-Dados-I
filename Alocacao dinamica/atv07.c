#include <stdio.h>
#include <stdlib.h>

int **createMatrix(int i, int j);
void fillMatrix(int **matrix, int i, int j);
void printMatrix(int **matrix, int i, int j);
void freeMatrix(int **matrix, int i);
int findThreeLargest(int **matrix, int i, int j);

int main(void)
{
    int N = 0;
    int M = 0;

    printf("Enter the number of rows: ");
    scanf("%d", &N);

    printf("Enter the number of columns: ");
    scanf("%d", &M);

    int **matrix = createMatrix(N, M);

    fillMatrix(matrix, N, M);
    printMatrix(matrix, N, M);

    printf("\n");
    findThreeLargest(matrix, N, M);

    freeMatrix(matrix, N);

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

    for (k = 0; k < i; k++)
    {
        for (l = 0; l < j; l++)
        {
            matrix[k][l] = rand() % 100;
        }
    }
}

void printMatrix(int **matrix, int i, int j)
{
    int k = 0;
    int l = 0;

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
    }

    free(matrix);
}

int findThreeLargest(int **matrix, int i, int j)
{
    int k = 0;
    int l = 0;
    int largest = 0;
    int secondLargest = 0;
    int thirdLargest = 0;

    for (k = 0; k < i; k++)
    {
        for (l = 0; l < j; l++)
        {
            if (matrix[k][l] > largest)
            {
                thirdLargest = secondLargest;
                secondLargest = largest;
                largest = matrix[k][l];
            }
            else if (matrix[k][l] > secondLargest)
            {
                thirdLargest = secondLargest;
                secondLargest = matrix[k][l];
            }
            else if (matrix[k][l] > thirdLargest)
            {
                thirdLargest = matrix[k][l];
            }
        }
    }

    printf("Largest: %d\n", largest);
    printf("Second largest: %d\n", secondLargest);
    printf("Third largest: %d\n", thirdLargest);

    return 1;
}