#include <stdio.h>
#include <math.h>

#define N 10          // Number of grid points in each dimension
#define MAX_ITER 1000 // Maximum number of iterations
#define TOL 1e-6      // Tolerance for convergence

void initializeGrid(double u[N][N], double f[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            u[i][j] = 0.0; // Initial guess for u
            f[i][j] = 1.0; // Example source term
        }
    }

    // Set boundary conditions
    for (int i = 0; i < N; i++)
    {
        u[i][0] = 0.0;     // Bottom boundary
        u[i][N - 1] = 0.0; // Top boundary
        u[0][i] = 0.0;     // Left boundary
        u[N - 1][i] = 0.0; // Right boundary
    }
}

void printGrid(double u[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%.2lf\t", u[i][j]);
        }
        printf("\n");
    }
}

void solvePoisson(double u[N][N], double f[N][N])
{
    double h = 1.0 / (N - 1); // Grid spacing
    double h2 = h * h;
    int iter = 0;
    double diff;

    do
    {
        diff = 0.0;
        for (int i = 1; i < N - 1; i++)
        {
            for (int j = 1; j < N - 1; j++)
            {
                double u_new = 0.25 * (u[i + 1][j] + u[i - 1][j] + u[i][j + 1] + u[i][j - 1] - h2 * f[i][j]);
                diff = fmax(diff, fabs(u_new - u[i][j]));
                u[i][j] = u_new;
            }
        }
        iter++;
    } while (diff > TOL && iter < MAX_ITER);

    printf("Number of iterations: %d\n", iter);
}

int main()
{
    double u[N][N], f[N][N];

    initializeGrid(u, f);
    solvePoisson(u, f);

    printf("Solution grid (u):\n");
    printGrid(u);

    return 0;
}
