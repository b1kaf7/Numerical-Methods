#include <stdio.h>

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

void doolittleLU(double mat[N][N], double L[N][N], double U[N][N], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                L[i][j] = 1;
            else
                L[i][j] = 0;
            U[i][j] = 0;
        }
    }

    // Perform the Do-Little decomposition
    for (int k = 0; k < n; k++)
    {
        for (int j = k; j < n; j++)
        {
            U[k][j] = mat[k][j];
            for (int p = 0; p < k; p++)
            {
                U[k][j] -= L[k][p] * U[p][j];
            }
        }
        for (int i = k + 1; i < n; i++)
        {
            L[i][k] = mat[i][k];
            for (int p = 0; p < k; p++)
            {
                L[i][k] -= L[i][p] * U[p][k];
            }
            L[i][k] /= U[k][k];
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
    }
}

void backwardSubstitution(double U[N][N], double y[N], double x[N], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        x[i] = y[i];
        for (int j = i + 1; j < n; j++)
        {
            x[i] -= U[i][j] * x[j];
        }
        x[i] /= U[i][i];
    }
}

int main()
{
    int n;
    double mat[N][N], L[N][N], U[N][N];
    double b[N], y[N], x[N];

    printf("\nDOOLITTLE LU DECOMPOSITION\n");

    printf("\nEnter the size of the square matrix: ");
    scanf("%d", &n);

    printf("\nEnter the elements of the matrix A:\n");
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

    doolittleLU(mat, L, U, n);

    printf("\nLower triangular matrix (L):\n");
    print(L, n);

    printf("\nUpper triangular matrix (U):\n");
    print(U, n);

    // Solve Ly = b using forward substitution
    forwardSubstitution(L, b, y, n);

    // Solve Ux = y using backward substitution
    backwardSubstitution(U, y, x, n);

    printf("\nSolution vector x:\n");
    for (int i = 0; i < n; i++)
    {
        printf("x[%d] = %.2lf\n", i + 1, x[i]);
    }

    return 0;
}
