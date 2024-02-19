#include <stdio.h>

int _double(int *A, int *B)
{
    *A = 2 * *A;
    *B = 2 * *B;
    return 1;
}

int main()
{
    int a, b;

    scanf("%d %d", &a, &b);
    printf("%d %d\n", a, b);

    if (_double(&a, &b))
        printf("%d %d", a, b);

    return 1;
}
