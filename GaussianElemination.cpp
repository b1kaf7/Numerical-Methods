#include <stdio.h>

#define MAX_SIZE 10

void solve(int n, double a[MAX_SIZE][MAX_SIZE], double b[MAX_SIZE], double x[MAX_SIZE]) {
    int i, j, k;
    double factor;

    // Forward elimination
    for (k = 0; k < n - 1; k++) {
        if (a[k][k] == 0) {
            printf("Method fails\n");
            return;
        }

        for (i = k + 1; i < n; i++) {
            factor = a[i][k] / a[k][k];
            for (j = k + 1; j < n; j++) {
                a[i][j] -= factor * a[k][j];
            }
            b[i] -= factor * b[k];
        }
    }

    // Back substitution
    for (i = n - 1; i >= 0; i--) {
        x[i] = b[i];
        for (j = i + 1; j < n; j++) {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];
    }
}

int main() {
    int n;
    
    printf("\nGAUSSIAN ELIMINATION METHOD\n");
    
    printf("\nEnter the number of equations: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX_SIZE) {
        printf("Invalid number of equations. It should be between 1 and %d.\n", MAX_SIZE);
        return 1;
    }

    double a[MAX_SIZE][MAX_SIZE], b[MAX_SIZE], x[MAX_SIZE];

    printf("\nEnter the coefficients of the equations:\n");
    for (int i = 0; i < n; i++) {
        printf("Equation %d coefficients: ", i + 1);
        for (int j = 0; j < n; j++) {
            scanf("%lf", &a[i][j]);
        }
    }

    printf("\nEnter the constant terms of the equations:\n");
    for (int i = 0; i < n; i++) {
        printf("b[%d]: ", i + 1);
        scanf("%lf", &b[i]);
    }

    solve(n, a, b, x);

    printf("\nThe solution vector is:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = %.6lf\n", i, x[i]);
    }

    return 0;
}

