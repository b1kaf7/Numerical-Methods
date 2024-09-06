#include <stdio.h>

#define N 10

void print(double mat[N][N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2lf\t", mat[i][j]);
        }
        printf("\n");
    }
}

void gaussJordan(double mat[N][N], double inv[N][N], int n) {
    double temp;
    // Initialize the identity matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                inv[i][j] = 1;
            else
                inv[i][j] = 0;
        }
    }

    // Applying Gauss-Jordan elimination
    for (int i = 0; i < n; i++) {
        if (mat[i][i] == 0) {
            printf("Matrix is singular. Cannot find its inverse.\n");
            return;
        }

        // Make the diagonal element 1
        temp = mat[i][i];
        for (int j = 0; j < n; j++) {
            mat[i][j] /= temp;
            inv[i][j] /= temp;
        }

        // Make other elements in the column zero
        for (int j = 0; j < n; j++) {
            if (i != j) {
                temp = mat[j][i];
                for (int k = 0; k < n; k++) {
                    mat[j][k] -= temp * mat[i][k];
                    inv[j][k] -= temp * inv[i][k];
                }
            }
        }
    }
}

int main() {
    int n;
    double mat[N][N], inv[N][N];
    
	printf("\nMATRIX INVERESION WITH GAUSS JORDAN METHOD\n");
	
    printf("\nEnter the size of the square matrix: ");
    scanf("%d", &n);

    printf("\nEnter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &mat[i][j]);
        }
    }

    gaussJordan(mat, inv, n);

    printf("\nInverse of the matrix:\n");
    print(inv, n);

    return 0;
}

