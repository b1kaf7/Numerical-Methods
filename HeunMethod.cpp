#include<stdio.h>
#include<math.h>
#define f(x,y) 2*(x) + y

int main() {
	
    printf("\nHeun's Method'\n");
    
    float x0, y0, x1, y1, xn, h, yn, m1, m2;
    int i, n; 
    
    printf("\nEnter the value of x0 and y0 respectively: ");
    scanf("%f %f", &x0, &y0);
    
    printf("\nEnter the value of step size h: ");
    scanf("%f", &h);
    
    printf("\nEnter number of steps: ");
    scanf("%d", &n);
    
    printf("\n x0 \t y0 \t m1 \t m2 \t yn \n");
    for(i=0; i<n; i++) {
        m1 = f(x0,y0);
        x1 = x0 + h;
        y1 = y0 + h * m1;
        m2 = f(x1,y1);
        
        yn = y0 + h/2 * (m1 + m2);
        printf("\n %.3f \t %.3f \t %0.3f \t %.3f \t %.3f \n", x0, y0, m1, m2, yn);
        
        y0 = yn;
        x0 = x0 + h;
    } 
    return 0;
}
