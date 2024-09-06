#include <stdio.h>

#define MAX_SIZE 10

void swapRows(double a[MAX_SIZE][MAX_SIZE], double b[MAX_SIZE], int i, int j, int n) {
    double temp;
    for (int k = 0; k < n; k++) {
        temp = a[i][k];
        a[i][k] = a[j][k];
        a[j][k] = temp;
    }
    temp = b[i];
    b[i] = b[j];
    b[j] = temp;
}

void solve(int n, double a[MAX_SIZE][MAX_SIZE], double b[MAX_SIZE], double x[MAX_SIZE]) {
    int i, j, k, maxIdx;
    double maxVal, temp;

    // Forward elimination with partial pivoting
    for (i = 0; i < n - 1; i++) {
        maxIdx = i;
        maxVal = a[i][i];
        for (j = i + 1; j < n; j++) {
            if (a[j][i] > maxVal) {
                maxVal = a[j][i];
                maxIdx = j;
            }
        }
        if (maxIdx != i) {
            swapRows(a, b, i, maxIdx, n);
        }
        for (j = i + 1; j < n; j++) {
            temp = a[j][i] / a[i][i];
            for (k = i; k < n; k++) {
                a[j][k] -= temp * a[i][k];
            }
            b[j] -= temp * b[i];
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
    printf("\nGAUSSIAN ELEMINATION WITH PIVOTING\n");
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

