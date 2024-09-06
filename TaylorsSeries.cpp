#include<stdio.h>

#define F(x, y) ((x)*(x) + (y)*(y))
#define dF(x, y) (2*(x) + 2*(y)*F(x, y))
#define ddF(x, y) (2 + 2*F(x, y) + 2*(y)*dF(x, y))

int main() {
    double x0, y0, x, y;
    
    printf("\nSolution of ODE by Taylor's Series\n");
    
    printf("\nEnter the initial value of x0: ");
    scanf("%lf", &x0);
    
    printf("\nEnter the initial value of y for %.3lf: ", x0);
    scanf("%lf", &y0);
    
    printf("\nEnter the value of x for which y is required: ");
    scanf("%lf", &x);
    
    double h = x - x0;
    
    y = y0 + h*F(x0, y0) + (h*h)/2*dF(x0, y0) + (h*h*h)/6*ddF(x0, y0);
    
    printf("\nSolution of given problem with given initial value is %lf\n", y);
    
    return 0;
}

