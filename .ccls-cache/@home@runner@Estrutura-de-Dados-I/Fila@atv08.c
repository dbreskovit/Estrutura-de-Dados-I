#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void push(int fila[], int valor)
{
    int i;
    if (fila[9] != 0)
    {
        printf("A fila está cheia\n");
    }
    else
    {
        for (i = 0; i < 10; i++)
        {
            if (fila[i] == 0)
            {
                fila[i] = valor;
                break;
            }
        }
    }
}

void pop(int fila[])
{
    int i;
    if (fila[0] == 0)
    {
        printf("A fila está vazia\n");
    }
    else
    {
        for (i = 0; i < 10; i++)
        {
            if (fila[i] == 0)
            {
                fila[i - 1] = 0;
                break;
            }
        }
    }
}

void imprimir(int fila[])
{
    int i;
    for (i = 0; i < 10; i++)
    {
        printf("%d ", fila[i]);
    }
    printf("\n");
}

void buscar(int fila[], int valor)
{
    int i;
    for (i = 0; i < 10; i++)
    {
        if (fila[i] == valor)
        {
            printf("O valor %d está na posição %d\n", valor, i);
            break;
        }
    }
}

int main(void)
{

    int fila[10];
    int i, valor, opcao;

    for (i = 0; i < 10; i++)
    {
        fila[i] = 0;
    }

    do
    {
        printf("\n");
        printf("1 - Inserir na fila\n");
        printf("2 - Remover da fila\n");
        printf("3 - Imprimir fila\n");
        printf("4 - Buscar na fila\n");
        printf("0 - Sair\n");
        printf("Digite uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            push(fila, valor);
            break;
        case 2:

            pop(fila);
            break;
        case 3:
            imprimir(fila);
            break;
        case 4:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            buscar(fila, valor);
            break;
        case 0:
            printf("Saindo...\n");
            break;
        }
    } while (opcao != 0);

    return 1;
}