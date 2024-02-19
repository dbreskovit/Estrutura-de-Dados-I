#include <stdio.h>
#include <math.h>

int num;

int sum_pow_three(int n)
{
    if (!n)
        return 0;
    return pow(n, 3) + sum_pow_three(n - 1);
}

int main()
{
    printf("Informe Um Numero Inteiro e Positivo: ");

    if (scanf("%d", &num) == 1)
    {
        if (num > 0)
        {
            printf("S(n): 1^3 + ... + %d^3: %d \n", num, sum_pow_three(num));
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
