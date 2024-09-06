#include<stdio.h>
#include<math.h>

int fact(int n){
    if(n==0) return 1;
    else return(n*fact(n-1));
}

int main(){
    int n, i, j, k;
    float val=0, term1, term2, xp, x[10], fx[10], bd[10], h, s, prev;

    // Input the number of points
    printf("Enter the number of points: ");
    scanf("%d", &n);

    // Input values of data points
    printf("Enter values of data points:\n");
    for(i=0; i<n; i++){
        scanf("%f%f", &x[i], &fx[i]);
    }

    // Input the value at which derivative is required
    printf("Enter the value at which derivative is required: ");
    scanf("%f", &xp);

    h = x[1] - x[0];
    s = (xp - x[n-1]) / h;

    // Calculating backward difference
    for(i=0; i<n; i++){
        bd[i] = fx[i];
    }
    for(i=0; i<n; i++){
        for(j=n-1; j>i; j--){
            bd[j] = bd[j] - bd[j-1];
        }
    }

    // Calculating value of derivative
    val = bd[n-1];
    prev = 1;
    for(i=1; i<n; i++){
        term1 = 1;
        for(k=2; k<=i; k++){
            term1 = term1 * (s + k - 1);
        }
        term2 = (s - i) * prev;
        prev = term1 + term2;
        val += (bd[n-i-1] * (term1 + term2)) / fact(i);
    }

    // Normalizing by step size 'h'
    val /= h;

    printf("Value of first derivative = %f\n", val);

    return 0;
}

