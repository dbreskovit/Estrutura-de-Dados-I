#include <stdio.h>

int num;

int fat(int n)
{
    if (!n)
        return 1;
    else
        return n * fat(n - 1);
}

int sfat(int n)
{
    if (!n)
        return 1;
    else
        return fat(n) * sfat(n - 1);
}

int main()
{
    printf("Informe Um Numero Inteiro e Positivo: ");

    if (scanf("%d", &num) == 1)
    {
        if (num > 0)
        {
            printf("sf(%d): 1! * ... * %d!: %d \n", num, num, sfat(num));
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
