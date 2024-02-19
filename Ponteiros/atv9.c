#include <stdio.h>

void reverter(int num, int *resultado)
{
    if (!num)
        return;
    *resultado = (*resultado * 10) + (num % 10);
    reverter(num / 10, resultado);
}

int main()
{
    int input = 1234;
    int output = 0;
    reverter(input, &output);
    printf("%d\n", input);
    printf("%d\n", output);
    return 1;
}
