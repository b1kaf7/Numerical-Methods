#include <stdio.h>
#include <math.h>

#define N 10

void print(double mat[N][N], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%.2lf\t", mat[i][j]);
        }
        printf("\n");
    }
}

void cholesky(double mat[N][N], double L[N][N], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (i == j)
            {
                double sum = 0;
                for (int k = 0; k < j; k++)
                {
                    sum += L[j][k] * L[j][k];
                }
                L[j][j] = sqrt(mat[j][j] - sum);
            }
            else
            {
                double sum = 0;
                for (int k = 0; k < j; k++)
                {
                    sum += L[i][k] * L[j][k];
                }
                L[i][j] = (mat[i][j] - sum) / L[j][j];
            }
        }
    }
}

void forwardSubstitution(double L[N][N], double b[N], double y[N], int n)
{
    for (int i = 0; i < n; i++)
    {
        y[i] = b[i];
        for (int j = 0; j < i; j++)
        {
            y[i] -= L[i][j] * y[j];
        }
        y[i] /= L[i][i];
    }
}

void backwardSubstitution(double L[N][N], double y[N], double x[N], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        x[i] = y[i];
        for (int j = i + 1; j < n; j++)
        {
            x[i] -= L[j][i] * x[j];
        }
        x[i] /= L[i][i];
    }
}

int main()
{
    int n;
    double mat[N][N], L[N][N];
    double b[N], y[N], x[N];

    printf("\nCHOLESKY METHOD\n");

    printf("\nEnter the size of the square matrix: ");
    scanf("%d", &n);

    printf("\nEnter the elements of the symmetric positive-definite matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%lf", &mat[i][j]);
        }
    }

    printf("\nEnter the elements of the vector b:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &b[i]);
    }

    cholesky(mat, L, n);

    printf("\nLower triangular matrix (L) from Cholesky decomposition:\n");
    print(L, n);

    // Solve Ly = b using forward substitution
    forwardSubstitution(L, b, y, n);

    // Solve L^T x = y using backward substitution
    backwardSubstitution(L, y, x, n);

    printf("\nSolution vector x:\n");
    for (int i = 0; i < n; i++)
    {
        printf("x[%d] = %.2lf\n", i + 1, x[i]);
    }

    return 0;
}
