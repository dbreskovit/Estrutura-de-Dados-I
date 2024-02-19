#include <stdio.h>

int num;

int sum(int n)
{
    if (!n)
        return 0;
    return n + sum(n - 1);
}

int main()
{
    printf("Informe Um Numero Inteiro e Positivo: ");

    if (scanf("%d", &num) == 1)
    {
        if (num > 0)
        {
            printf("Soma de %d ate 1: %d\n", num, sum(num));
            return 1;
        }
        else
        {
            printf("Erro: voce informou um numero negativo.\n");
            return 0;
        }
    }
    else
    {
        printf("Erro: o que voce informou nao eh um numero.\n");
        return 0;
    }
}
