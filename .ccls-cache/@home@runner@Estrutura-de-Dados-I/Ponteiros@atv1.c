#include <stdio.h>

int main()
{
    int x = 0, *px = &x;
    float y = 0.0, *py = &y;
    char z = 65, *pz = &z;

    printf("Valores Iniciais:\n");
    printf("x = %d\n", x);
    printf("y = %f\n", y);
    printf("z = %c\n", z);

    *px = 10;
    *py = 10.5;
    *pz = 97;

    printf("Novos Valores:\n");
    printf("x = %d\n", x);
    printf("y = %f\n", y);
    printf("z = %c\n", z);
    
    return 1;
}
