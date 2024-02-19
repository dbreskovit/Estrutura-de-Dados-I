#include <stdio.h>

void sum(int *a, int b)
{
    *a += b;
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d %d\n", a, b);
    sum(&a, b);
    printf("%d %d\n", a, b);
    return 1;
}
