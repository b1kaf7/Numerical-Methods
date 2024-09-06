#include <stdio.h>

#define N 10

void gaussJordan(double mat[N][N], double b[N], int n) {
    double temp;
    
    for (int i = 0; i < n; i++) {
        if (mat[i][i] == 0) {
            printf("Mathematical Error! Division by zero encountered.\n");
            return;
        }
        
        // Make diagonal elements 1
        temp = mat[i][i];
        for (int j = 0; j < n; j++) {
            mat[i][j] /= temp;
        }
        b[i] /= temp;
        
        // Eliminate non-diagonal elements
        for (int k = 0; k < n; k++) {
            if (k != i) {
                temp = mat[k][i];
                for (int j = 0; j < n; j++) {
                    mat[k][j] -= temp * mat[i][j];
                }
                b[k] -= temp * b[i];
            }
        }
    }
}

int main() {
    int n;
    double mat[N][N], b[N];

    printf("\nGAUSS JORDAN ELEMINATION\n");
    
    printf("\nEnter the size of the square matrix: ");
    scanf("%d", &n);

    printf("\nEnter the elements of the augmented matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &mat[i][j]);
        }
        scanf("%lf", &b[i]);
    }

    gaussJordan(mat, b, n);

    printf("\nThe solution vector (x) is:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = %.6lf\n", i, b[i]);
    }

    return 0;
}

