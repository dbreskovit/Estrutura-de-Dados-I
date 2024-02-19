#include <stdio.h>

int main()
{
    int x = 0, y = 0;
    printf("Endereco de x: %p\n", &x);
    printf("Endereco de y: %p\n", &y);
    printf("Maior endereco: %p\n", &x > &y ? &x : &y);

    return 1;
}
