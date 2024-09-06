#include <stdio.h>

int main()
{
    float xp;            // Point at which derivative is required
    float x0, x1, x2;    // Data points
    float fx0, fx1, fx2; // Function values at data points
    float h;             // Step size
    float val;           // Value of derivative

    // Input data points
    printf("Enter the value at which derivative is required: ");
    scanf("%f", &xp);

    printf("Enter three data points (x, f(x)):\n");
    printf("x0 f(x0): ");
    scanf("%f %f", &x0, &fx0);
    printf("x1 f(x1): ");
    scanf("%f %f", &x1, &fx1);
    printf("x2 f(x2): ");
    scanf("%f %f", &x2, &fx2);

    // Calculate step size
    h = x1 - x0;

    // Calculate forward differences
    float fd0 = fx0;
    float fd1 = fx1 - fx0;
    float fd2 = fx2 - fx1;

    // Calculate value of derivative using forward difference approximation
    val = fd0 + (xp - x0) * fd1 / h + (xp - x0) * (xp - x1) * fd2 / (2 * h * h);

    printf("Value of first derivative = %f\n", val);

    return 0;
}
