#include <stdio.h>

int num;

void natural_nums_until_num(int n, int k)
{
    if (n == k)
        printf("%d ", k);
    else
    {
        printf("%d ", n);
        natural_nums_until_num(n + 1, k);
    }
}

int main()
{
    printf("Informe Um Numero Inteiro e Positivo: ");

    if (scanf("%d", &num) == 1)
    {
        if (num > 0)
        {
            natural_nums_until_num(0, num);
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
