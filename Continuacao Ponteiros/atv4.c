#include <stdio.h>
#include <math.h>
#include "lib.h"

typedef struct ponto2d
{
    float x;
    float y;
} ponto2d;

void dAB(ponto2d *p1, ponto2d *p2, float *dist);

int main(void)
{
    ponto2d ponto_inicial;
    ponto2d ponto_final;

    printf("Enter the starting point (x, y): ");
    ponto_inicial.x = readFloat();
    ponto_inicial.y = readFloat();

    printf("Enter the end point (x, y): ");
    ponto_final.x = readFloat();
    ponto_final.y = readFloat();

    float distance;
    dAB(&ponto_inicial, &ponto_final, &distance);

    printf("The distance between the points is: %.2f\n", distance);

    return 1;
}

void dAB(ponto2d *p1, ponto2d *p2, float *dist)
{
    *dist = sqrt(pow((p1->x - p2->x), 2) + pow((p1->y - p2->y), 2));
}