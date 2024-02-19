#include <stdio.h>

int n1, n2;

int number_exp_pow(int k, int n)
{
    if (n == 1)
        return k;
    return k * number_exp_pow(k, n - 1);
}

int main()
{
    printf("Informe Dois Numero Inteiro e Positivo (Base / Expoente): \n");

    if ((scanf("%d", &n1) && scanf("%d", &n2)) == 1)
    {
        if (n1 > 0 && n2 > 0)
        {
            printf("%d elevado a %d: %d", n1, n2, number_exp_pow(n1, n2));
            return 1;
        }
        else
        {
            printf("Erro: voce informou um dos numero negativo.\n");
            return 0;
        }
    }
    else
    {
        printf("Erro: o que voce informou nao eh um numero.\n");
        return 0;
    }
}
