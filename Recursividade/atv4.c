#include <stdio.h>

int num;

int fibo(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return (fibo(n - 1) + fibo(n - 2));
}

int main()
{
    printf("Informe Um Numero Inteiro e Positivo: ");

    if (scanf("%d", &num) == 1)
    {
        if (num >= 0)
        {
            printf("%d termo de Fibonacci: %d", num, fibo(num));
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
