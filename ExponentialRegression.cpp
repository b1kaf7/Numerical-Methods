#include <stdio.h>
#include <math.h>

#define N 5 // Number of data points

// Data points
double data_x[N] = {1.0, 2.0, 3.0, 4.0, 5.0};
double data_y[N] = {2.718, 7.389, 20.086, 54.598, 148.413};

// Function to perform exponential regression
void exponential_regression(double x[], double y[], int n, double *a, double *b)
{
    double sum_x = 0.0, sum_y = 0.0, sum_x2 = 0.0, sum_xy = 0.0;

    // Calculate sums needed for regression formulas
    for (int i = 0; i < n; i++)
    {
        sum_x += x[i];
        sum_y += log(y[i]);
        sum_x2 += x[i] * x[i];
        sum_xy += x[i] * log(y[i]);
    }

    // Calculate coefficients a and b
    double denominator = n * sum_x2 - sum_x * sum_x;
    *a = (sum_x2 * sum_y - sum_x * sum_xy) / denominator;
    *b = (n * sum_xy - sum_x * sum_y) / denominator;
}

int main()
{
    double a, b;

    // Perform exponential regression
    exponential_regression(data_x, data_y, N, &a, &b);

    // Print the regression equation
    printf("Exponential Regression: y = %.6lf * e^(%.6lf * x)\n", exp(a), b);

    return 0;
}
