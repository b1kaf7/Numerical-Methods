#include<stdio.h>
#define f(x,y) 2*(x) + y

int main() {
	
    printf("\nEuler's Method'\n");

    float x0, y0, xn, h, yn, slope;
    int i, n; 
    
    printf("\nEnter the value of x0 and y0 respectively: ");
    scanf("%f %f", &x0, &y0);
    
    printf("\nEnter the value of step size h: ");
    scanf("%f", &h);
    
    printf("\nEnter number of steps: ");
    scanf("%d", &n);
    
    printf("\n x0 \t y0 \t slope \t yn \n");
    for(i=0; i<n; i++) {
        slope = f(x0,y0);
        yn = y0 + h * slope;
        
        printf("\n %.3f \t %.3f \t %0.3f \t %.3f\n", x0, y0, slope, yn);
        
        y0 = yn;
        x0 = x0 + h;
    } 
    return 0;
}
