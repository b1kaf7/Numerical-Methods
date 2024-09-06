#include <stdio.h>
#include <math.h>

// Function to integrate
double f(double x) {
    return 1 / (1 + x * x);  // Example function: f(x) = 1 / (1 + x^2)
}

// Simpson's 3/8 rule function
double simpsonsThreeEighths(double a, double b, int n) {
    if (n % 3 != 0) {
        printf("n must be a multiple of 3 for Simpson's 3/8 rule.\n");
        return -1;
    }

    double h = (b - a) / n;
    double sum = f(a) + f(b);
    
    for (int i = 1; i < n; i++) {
        if (i % 3 == 0) {
            sum += 2 * f(a + i * h);
        } else {
            sum += 3 * f(a + i * h);
        }
    }
    
    sum = (3 * h / 8) * sum;
    return sum;
}

int main() {
    double a, b;
    int n;
    
    // Input
    printf("Enter the lower limit a: ");
    scanf("%lf", &a);
    printf("Enter the upper limit b: ");
    scanf("%lf", &b);
    printf("Enter the number of subintervals n (must be multiple of 3): ");
    scanf("%d", &n);
    
    // Calculate the integral
    double result = simpsonsThreeEighths(a, b, n);
    if (result != -1) {
        printf("The integral of the function from %lf to %lf is: %lf\n", a, b, result);
    }
    
    return 0;
}
