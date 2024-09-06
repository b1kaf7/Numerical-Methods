#include <stdio.h>

int main()
{
    int poly[10], m, r, i, q[10];

    printf("\nEnter the highest degree of the polynomial: ");
    scanf("%d", &m);

    // Input coefficients
    for (i = 0; i <= m; i++)
    {
        printf("\nEnter the coefficient of x^%d: ", m - i);
        scanf("%d", &poly[i]);
    }

    // Input value of 'r' for (x - r)
    printf("\nEnter the value of constant 'r' in (x - r): ");
    scanf("%d", &r);

    // Initialize quotient with the first coefficient
    q[0] = poly[0];

    // Applying synthetic division
    for (i = 1; i <= m; i++)
    {
        q[i] = q[i - 1] * r + poly[i];
    }

    // Print coefficients of quotient
    printf("\nCoefficients of quotient are: \n");
    for (i = 0; i < m; i++)
    {
        printf("%d ", q[i]);
    }

    // Print remainder
    printf("\nRemainder is: %d\n", q[m]);

    return 0;
}
