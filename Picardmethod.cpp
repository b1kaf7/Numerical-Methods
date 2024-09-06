#include<stdio.h>
#include<math.h>
#define f(x,y) (x)*(x) + (y)*(y)
#define f1(x,y) (x*x*x)/3
#define f2(x,y) pow(x,3)/3 + pow(x,7)/63

int main() {
    printf("\nPicard's Method\n");
    
    float x0, y0, x1, y1, y2;
    
    printf("\nEnter the value of x0 and y0 respectively: ");
    scanf("%f %f", &x0, &y0);
    printf("\nEnter the value of x: ");
    scanf("%f", &x1);
    
    y1 = y0 + (f1(x1,y0) - f1(x0,y0));
    y2 = y0 + (f2(x1,y0) - f2(x0,y0));
    printf("\nThe value of y1 at x = %.3f is %.3f\n", x1, y1);
    printf("\nThe value of y2 at x = %.3f is %.3f\n", x1, y2);
    
    return(0);
}
