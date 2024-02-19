#include <stdio.h>

int num;

float s(float n)
{
    if (!n)
        return 0;
    return ((1.0F + n * n) / n) + s(n - 1.0F);
}

int main()
{
    printf("Informe Um Numero Inteiro e Positivo: ");

    if (scanf("%d", &num) == 1)
    {
        if (num > 0)
        {
            printf("S: %f", s(num));
            return 1;
        }
        else
        {
            printf("Erro: voce informou um numero negativo ou menor que zero.\n");
            return 0;
        }
    }
    else
    {
        printf("Erro: o que voce informou nao eh um numero.\n");
        return 0;
    }
}
