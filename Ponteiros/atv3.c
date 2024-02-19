#include <stdio.h>

int reverse(int *A, int *B)
{
    *A = *A + *B;
    *B = *A - *B;
    *A = *A - *B;
    return 1;
}

int main()
{
    int a, b;

    scanf("%d %d", &a, &b);
    printf("%d %d\n", a, b);

    if (reverse(&a, &b))
        printf("%d %d", a, b);

    return 1;
}
