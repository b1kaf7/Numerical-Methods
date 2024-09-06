#include <stdio.h>

#define f1(x, y, z) z
#define f2(x, y, z) 6 * x

float euler(float x0, float y0, float z0, float xn, float h)
{
    float m1, m2, yn, zn;
    printf(" x0 \t y0 \t z0 \t slope \t yn/zn \n");
    while (x0 < xn)
    {
        m1 = f1(x0, y0, z0);
        m2 = f2(x0, y0, z0);
        x0 = x0 + h;

        yn = y0 + h * m1;
        printf(" %.2f \t %.2f \t %.2f \t %.2f \t %.2f\n", x0, y0, z0, m1, yn);

        zn = z0 + h * m2;
        printf(" %.2f \t %.2f \t %.2f \t %.2f \t %.2f\n", x0, y0, z0, m1, zn);
        y0 = yn;
        z0 = zn;
    }
    return yn;
}

int main()
{
    printf("Solving boundary value problem by shooting method with Euler's method\n");
    float x0, y0, z0, xn, yn, h, g[10], v[10];

    printf("Enter the boundary value x0 and y0: ");
    scanf("%f %f", &x0, &y0);
    printf("Enter the boundary value xn and yn: ");
    scanf("%f %f", &xn, &yn);
    printf("Enter the value of h: ");
    scanf("%f", &h);

    g[1] = (yn - y0) / (xn - x0);
    z0 = g[1];
    printf("\nStep 1: \n");
    v[1] = euler(x0, y0, z0, xn, h);

    if (v[1] != yn)
    {
        g[2] = g[1] / 2;
        z0 = g[2];
        printf("\nStep 2: \n");
        v[2] = euler(x0, y0, z0, xn, h);
    }

    int i = 2;
    while (v[i] != yn)
    {
        g[i + 1] = g[i] - ((v[i] - yn) / (v[i] - v[i - 1]) * (g[i] - g[i - 1]));
        z0 = g[i + 1];
        printf("\nStep %d: \n", i + 1);
        v[i + 1] = euler(x0, y0, z0, xn, h);
        i++;
    }

    return 0;
}
