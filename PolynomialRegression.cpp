#include <stdio.h>
#include <math.h>

int main()
{
    int i, j, k, m, n;
    float x[20], y[20], u, a[10], c[20][20], power, r;

    printf("Enter the degree of the polynomial: ");
    scanf("%d", &m);

    printf("Enter number of data points: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        printf("Enter values of x[%d] and y[%d]: ", i, i);
        scanf("%f%f", &x[i], &y[i]);
    }

    // Constructing the coefficient matrix
    for (j = 1; j <= m + 1; j++)
    {
        for (k = 1; k <= m + 1; k++)
        {
            c[j][k] = 0;
            for (i = 1; i <= n; i++)
            {
                power = pow(x[i], j + k - 2);
                c[j][k] += power;
            }
        }
    }

    // Constructing the augmented matrix
    for (j = 1; j <= m + 1; j++)
    {
        c[j][m + 2] = 0;
        for (i = 1; i <= n; i++)
        {
            r = pow(x[i], j - 1);
            c[j][m + 2] += y[i] * r;
        }
    }

    // Performing Gaussian elimination
    for (k = 1; k <= m + 1; k++)
    {
        for (i = 1; i <= m + 1; i++)
        {
            if (i != k)
            {
                u = c[i][k] / c[k][k];
                for (j = k; j <= m + 2; j++)
                {
                    c[i][j] -= u * c[k][j];
                }
            }
        }
    }

    // Calculating coefficients
    for (i = 1; i <= m + 1; i++)
    {
        a[i] = c[i][m + 2] / c[i][i];
    }

    // Printing the matrix and coefficients
    printf("\n");
    printf("Matrix C:\n");
    for (i = 1; i <= m + 1; i++)
    {
        for (j = 1; j <= m + 2; j++)
        {
            printf("%.2f\t", c[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    printf("Coefficients of the polynomial:\n");
    for (i = 1; i <= m + 1; i++)
    {
        printf("a[%d] = %.6f\n", i, a[i]);
    }

    return 0;
}
