#include <stdio.h>

void addDigits(unsigned int n, unsigned int *sum)
{
    if (!n) return;
    *sum += n % 10;
    addDigits(n / 10, sum);
}

int main()
{
    unsigned int num, soma = 0;
    
    scanf("%u", &num);
    addDigits(num, &soma);

    printf("%u\n", soma);

    return 1;
}