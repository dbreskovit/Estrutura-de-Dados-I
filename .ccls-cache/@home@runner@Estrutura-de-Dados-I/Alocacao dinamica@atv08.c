#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *vetor = NULL;
    int n = 10;
    int i = 0;
    int j = 0;
    int aux = 0;

    vetor = (int *)malloc(n * sizeof(int));

    if (vetor == NULL)
    {
        printf("Memory allocation error!\n");
        exit(1);
    }

    printf("Enter the numbers: ");
    scanf("%d", &aux);

    while (aux != 0)
    {
        vetor[i] = aux;
        i++;

        if (i == n)
        {
            n += 10;

            int *vetor2 = (int *)malloc(n * sizeof(int));

            for (j = 0; j < i; j++)
                vetor2[j] = vetor[j];

            free(vetor);

            vetor = vetor2;
        }

        scanf("%d", &aux);
    }

    for (j = 0; j < i; j++)
        printf("%d ", vetor[j]);

    printf("\n");

    free(vetor);
    vetor = NULL;

    return 1;
}