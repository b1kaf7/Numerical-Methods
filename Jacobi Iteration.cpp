#include <stdio.h>
#include <math.h>

#define N 10
#define MAX_ITER 1000
#define TOLERANCE 1e-6

void print(double x[N], int n) {
    for (int i = 0; i < n; i++) {
        printf("%.6lf\t", x[i]);
    }
    printf("\n");
}

void jacobi(double A[N][N], double b[N], double x[N], int n) {
    double new_x[N];
    int iter = 0;
    double error = TOLERANCE + 1;

    while (error > TOLERANCE && iter < MAX_ITER) {
        error = 0.0;

        // Compute new approximation for each variable
        for (int i = 0; i < n; i++) {
            new_x[i] = b[i];
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    new_x[i] -= A[i][j] * x[j];
                }
            }
            new_x[i] /= A[i][i];
        }

        for (int i = 0; i < n; i++) {
            error += fabs(new_x[i] - x[i]);
        }

        // Update x with new approximation
        for (int i = 0; i < n; i++) {
            x[i] = new_x[i];
        }

        iter++;
    }

    if (iter >= MAX_ITER) {
        printf("Maximum number of iterations reached.\n");
    } else {
        printf("Solution converged in %d iterations.\n", iter);
    }
}

int main() {
    int n;
    double A[N][N], b[N], x[N];
    
	printf("\nJACOBI ITERATION METHOD\n");

    printf("\nEnter the size of the square matrix: ");
    scanf("%d", &n);

    printf("\nEnter the elements of the coefficient matrix (A):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    printf("\nEnter the elements of the constant vector (b):\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &b[i]);
    }

    printf("\nEnter an initial guess for the solution vector (x):\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &x[i]);
    }

    jacobi(A, b, x, n);

    printf("\nThe solution vector (x) is:\n");
    print(x, n);

    return 0;
}

