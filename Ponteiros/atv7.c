#include <stdio.h>

int main()
{
    int num, *pnum = &num;

    if (num == &pnum)
        printf("a) num == &pnum\n");

    // if (pnum == *num)   <----- Ocorre um erro de compilação
    //     printf("b) pnum == *num\n");

    if (num == *pnum)
        printf("c) num == *pnum\n");

    if (pnum == &num)
        printf("d) pnum == &num\n");

    return 1;
}
