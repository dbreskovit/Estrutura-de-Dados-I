#include <stdio.h>

void convert(int mnts, int *h, int *m)
{
    *h = mnts / 60;
    *m = mnts % 60;
}

int main()
{
    int mnts, h, m;

    scanf("%d", &mnts);

    convert(mnts, &h, &m);

    if (60 * h + m == mnts)
        printf("%dh:%dmin\n", h, m);

    return 1;
}
