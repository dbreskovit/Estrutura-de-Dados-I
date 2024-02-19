#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846

void calc_esfera(float R, float *area, float *volume);

int main()
{
    float R, area, volume;
    scanf("%f", &R);
    calc_esfera(R, &area, &volume);
    printf("Area: %.2fm%c\nVolume: %.2fm%c\n", area, 253, volume, 252);

    return 1;
}

void calc_esfera(float R, float *area, float *volume)
{
    *area = 4 * PI * pow(R, 2);
    *volume = (4 * PI * pow(R, 3)) / 3;
}
