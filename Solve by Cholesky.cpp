#include <stdio.h>
#include <math.h>

#define N 10

void printMatrix(double mat[N][N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2lf\t", mat[i][j]);
        }
        printf("\n");
    }
}

void forwardSubstitution(double L[N][N], double b[N], double y[N], int n) {
    for (int i = 0; i < n; i++) {
        double sum = 0;
        for (int j = 0; j < i; j++) {
            sum += L[i][j] * y[j];
        }
        y[i] = (b[i] - sum) / L[i][i];
    }
}

void backwardSubstitution(double LT[N][N], double y[N], double x[N], int n) {
    for (int i = n - 1; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < n; j++) {
            sum += LT[j][i] * x[j];
        }
        x[i] = (y[i] - sum) / LT[i][i];
    }
}

void cholesky(double mat[N][N], double L[N][N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (i == j) {
                double sum = 0;
                for (int k = 0; k < j; k++) {
                    sum += L[j][k] * L[j][k];
                }
                L[j][j] = sqrt(mat[j][j] - sum);
            } else {
                double sum = 0;
                for (int k = 0; k < j; k++) {
                    sum += L[i][k] * L[j][k];
                }
                L[i][j] = (mat[i][j] - sum) / L[j][j];
            }
        }
    }
}

int main() {
    int n;
    double A[N][N], L[N][N], b[N], y[N], x[N];

    printf("\nSOLVE SYSTEM OF LINEAR EQUATIONS USING CHOLESKY METHOD\n");
    
    printf("\nEnter the size of the square matrix: ");
    scanf("%d", &n);

    printf("\nEnter the elements of the symmetric positive-definite matrix A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    printf("\nEnter the elements of the vector b:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &b[i]);
    }

    cholesky(A, L, n);

    printf("\nLower triangular matrix (L) from Cholesky decomposition:\n");
    printMatrix(L, n);

    // Forward substitution: Ly = b
    forwardSubstitution(L, b, y, n);

    // Backward substitution: L^Tx = y
    backwardSubstitution(L, y, x, n);

    printf("\nThe solution vector x is:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = %.6lf\n", i, x[i]);
    }

    return 0;
}

